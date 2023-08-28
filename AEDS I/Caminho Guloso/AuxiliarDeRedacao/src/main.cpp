#include <time.h>
#include <fstream>

#include "output_functions.hpp"

using namespace std;

bool isPortugueseWordCharacter(char c) {
    // Função que teste se um caracter pode ou não pertencer a uma palavra.

    string acents = "áàâãéèêíïóôõúüçÁÀÂÃÉÈÊÍÏÓÔÕÚÜÇ";

    if (acents.find(c) != acents.npos) return true;

    return iswalnum(c);
};

void loadStopWordsFromFile(unordered_set<string> *stop_words) {
    fstream fs;

    string stop;

    // Abre o arquivo que armazena as stopwords
    fs.open("./dataset/stopwords.txt", std::fstream::in);

    // Lê as stopwords e as salva no arquivo
    while (getline(fs, stop)) {
        stop_words->emplace(stop);
    };

    // Fecha o arquivo
    fs.close();
};

char toLowerAccent(char c) {
    // Funciona com
    // "áàâãéèêíïóôõúüçÁÀÂÃÉÈÊÍÏÓÔÕÚÜÇ"

    int aux = c;

    if (aux == -61)
        return -61;
    else if (aux >= -128 && aux <= -118)
        return (aux + 32);
    else if (aux == -115)
        return (aux + 32);
    else if (aux == -113)
        return (aux + 32);
    else if (aux == -109)
        return (aux + 32);
    else if (aux == -108)
        return (aux + 32);
    else if (aux == -107)
        return (aux + 32);
    else if (aux == -102)
        return (aux + 32);
    else if (aux == -100)
        return (aux + 32);

    return tolower(c);
}

void loadExpressions(set<string> &expressions) {
    ifstream f("./dataset/expressoes.txt");
    string s, s2;

    while (getline(f, s)) {
        if (s != "") {
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] == '-' /*|| s[i] == '/' || s[i] == '_'*/) {
                    s[i] = '\0';
                } else {
                    s[i] = toLowerAccent(s[i]);
                }
            }
            // String auxiliar pros casos em que "-" é substituído por '\0'
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] != '\0') {
                    s2.push_back(s[i]);
                }
            }
            s2.insert(0, 1, ' ');
            s2.push_back(' ');
            expressions.insert(s2);
            s2.clear();
        }
    }
}

void processWord(string &word, int &words, int &sentenceWordCounter,
                 unordered_set<string> &stopWordsSet,
                 unordered_map<string, WordInfo> &wordsInfoInSentence,
                 int &acentos, int &paragraphs, int &linesCounter,
                 int &sentences,
                 unordered_map<string, WordInfo> &wordsInfoInFullText,
                 set<string, locale> &wordsInSentence, set<string,locale> &wordsInFullText,
                 int &stopWords, int &sentenceStopWordCounter) {
    words++;
    sentenceWordCounter++;

    if (stopWordsSet.count(word) == 0) {
        auto &info = wordsInfoInSentence[word];

        info.freq++;
        info.acents = acentos;
        info.paragraphs.emplace(paragraphs + 1);
        info.line.emplace(linesCounter + 1);
        info.sentence.emplace(sentences == 0 ? 1 : sentences + 1);
        info.positions.push_back(sentenceWordCounter);

        auto &info2 = wordsInfoInFullText[word];

        info2.freq++;
        info2.acents = acentos;
        info2.paragraphs.emplace(paragraphs + 1);
        info2.line.emplace(linesCounter == 0 ? 1 : linesCounter + 1);
        info2.sentence.emplace(sentences == 0 ? 1 : sentences + 1);
        info2.positions.push_back(sentenceWordCounter);

        wordsInSentence.emplace(word);

        wordsInFullText.emplace(word);

    } else {
        stopWords++;
        sentenceStopWordCounter++;
    }

    acentos = 0;
}

void processSentence(FILE *outputFile, int &sentenceWordCounter,
                     unordered_map<string, WordInfo> &wordsInfoInSentence,
                     int &paragraphs, int &sentences,
                     set<string, locale> &wordsInSentence, int &sentenceStopWordCounter,
                     vector<SentenceInfo> &sentencesInfo) {
    sentences++;

    SentenceInfo sentenceInfo;
    sentenceInfo.paragraph = paragraphs + 1;
    sentenceInfo.sentence = sentences == 0 ? 1 : sentences;
    sentenceInfo.words = sentenceWordCounter;
    sentenceInfo.wordsWithoutStopWords =
        sentenceWordCounter - sentenceStopWordCounter;

    sentencesInfo.push_back(sentenceInfo);

    showSentenceInformation(outputFile, &wordsInSentence, &wordsInfoInSentence,
                            sentenceWordCounter, sentenceStopWordCounter);

    unordered_map<string, WordInfo> emptyMap;
    emptyMap.reserve(10);
    wordsInfoInSentence = emptyMap;

    set<string, locale> emptySet;
    wordsInSentence = emptySet;

    sentenceWordCounter = 0;
    sentenceStopWordCounter = 0;
}

void processParagraph(FILE *outputFile, int &words, int &sentenceWordCounter,
                      unordered_map<string, WordInfo> &wordsInfoInSentence,
                      int &paragraphs, int &linesCounter, int &sentences,
                      set<string, locale> &wordsInSentence, int &stopWords,
                      int &sentenceStopWordCounter, int &end, int &begin,
                      vector<SentenceInfo> &sentencesInfo,
                      vector<ParagraphInfo> &paragraphsInfo) {
    paragraphs++;
    end = linesCounter - 1;

    ParagraphInfo info;
    info.paragraph = paragraphs;
    info.begin = begin;
    info.sentence = sentences == 0 ? 1 : sentences;
    info.words = words;
    info.wordsWithoutStopWords = words - stopWords;

    paragraphsInfo.push_back(info);

    if (sentences == 0) {
        processSentence(outputFile, sentenceWordCounter, wordsInfoInSentence,
                        paragraphs, sentences, wordsInSentence,
                        sentenceStopWordCounter, sentencesInfo);
    }

    showParagraphBeginningAndSentences(outputFile, begin,
                                       sentences == 0 ? 1 : sentences);

    begin = end + 2;

    sentences = 0;

    words = 0;

    stopWords = 0;
}

int main() {
    clock_t startExe, endExe;
    double execution_time;
    startExe = clock();

    locale loc("pt_BR.UTF-8");
    locale::global(loc);
    FILE *outputFile;

    // Abre o arquivo de saída em modo de escrita
    outputFile = fopen("dataset/output.txt", "w");

    showHeader(outputFile, "START PROCESS");
    showHeader(outputFile, "PARTIAL RESULT");

    // Geral
    int linesCounter = 0;  // Contador de linhas

    // Palavras
    set<string, locale> wordsInSentence;
    unordered_map<string, WordInfo> wordsInfoInSentence;
    set<string,locale> wordsInFullText;
    unordered_map<string, WordInfo> wordsInfoInFullText;

    wordsInfoInSentence.reserve(10);
    wordsInfoInFullText.reserve(25000);

    // Sentenças
    int sentenceWordCounter = 0;
    int sentenceStopWordCounter = 0;
    vector<SentenceInfo> sentencesInfo;

    // Paragráfos
    vector<ParagraphInfo> paragraphsInfo;

    int paragraphs = 0;
    int begin = 1;
    int end = 0;
    int sentences = 0;
    int words = 0;
    int stopWords = 0;

    unordered_set<string> stopWordsSet;
    loadStopWordsFromFile(&stopWordsSet);

    // Expressões
    string paragraphCopy = " ";

    set<string, locale> expressionsInParagraph;
    unordered_map<string, ExpressionInfo> expressionsInfoInParagraph;

    expressionsInfoInParagraph.reserve(10);

    set<string, locale> expressionsInFullText;
    unordered_map<string, ExpressionInfo> expressionsInfo;

    int caractersCounter = 0;
    vector<int> breakLinesPosition;

    set<string> expressions;
    loadExpressions(expressions);

    FILE *file;

    // Abre o arquivo de entrada em modo de leitura
    file = fopen("./dataset/ent.txt", "r");

    char aux, last;
    string word;

    int acentos = 0;

    while (fscanf(file, "%c", &aux) > 0) {
        caractersCounter++;
        if (aux == -61) acentos++;

        if (isPortugueseWordCharacter(aux)) {
            word += toLowerAccent(aux);
        } else {
            // Ignorando '-, /, _' no meio de uma palavra
            if (aux == '-' || aux == '/' || aux == '_') continue;

            if (!word.empty()) {
                paragraphCopy.append(word).append(" ");

                processWord(word, words, sentenceWordCounter, stopWordsSet,
                            wordsInfoInSentence, acentos, paragraphs,
                            linesCounter, sentences, wordsInfoInFullText,
                            wordsInSentence, wordsInFullText, stopWords,
                            sentenceStopWordCounter);
            };

            // \n
            if (aux == (char)10) {
                linesCounter++;
                paragraphCopy.push_back(' ');
                breakLinesPosition.push_back(paragraphCopy.size()-1);
            };

            if (last == (char)10 && aux == (char)10) {
                paragraphCopy.push_back(' ');

                for (auto &e : expressions) {
                    size_t pos = 0;

                    int counter = 0;
                    set<int> lines;

                    while ((pos = paragraphCopy.find(e, pos)) !=
                           std::string::npos) {
                        counter++;

                        // lines.insert(pos);

                        for (int i = 0; i < (int)breakLinesPosition.size();
                             i++) {
                            if ((int)pos < breakLinesPosition[i]) {
                                lines.emplace(begin + i);
                                break;
                            }
                        }

                        pos += (int)e.size();
                    };

                    if (counter != 0) {
                        expressionsInParagraph.emplace(e);
                        auto &info = expressionsInfoInParagraph[e];
                        info.cont = counter;
                        info.lines = lines;
                        info.acents = acentos;

                        expressionsInFullText.emplace(e);

                        auto &infoText = expressionsInfo[e];
                        infoText.cont += counter;
                        infoText.acents = acentos;

                        infoText.lines.insert(lines.begin(), lines.end());
                    }
                }

                showExpressionInformation(outputFile, expressionsInParagraph,
                                          expressionsInfoInParagraph);

                processParagraph(outputFile, words, sentenceWordCounter,
                                 wordsInfoInSentence, paragraphs, linesCounter,
                                 sentences, wordsInSentence, stopWords,
                                 sentenceStopWordCounter, end, begin,
                                 sentencesInfo, paragraphsInfo);

                paragraphCopy = " ";

                vector<int> emptyVector;
                breakLinesPosition = emptyVector;

                unordered_map<string,ExpressionInfo> emptyMap;
                emptyMap.reserve(10);
                expressionsInfoInParagraph = emptyMap;

                set<string, locale> emptySet;
                expressionsInParagraph = emptySet;
            };

            // fim de uma sentença
            if (aux == '?' || aux == '!' || aux == '.') {
                processSentence(outputFile, sentenceWordCounter,
                                wordsInfoInSentence, paragraphs, sentences,
                                wordsInSentence, sentenceStopWordCounter,
                                sentencesInfo);
            };

            word = "";
        }

        last = aux;
    }

    // Mostrando o ultimo paragrafo
    paragraphCopy.push_back(' ');

    for (auto &e : expressions) {
        size_t pos = 0;

        int counter = 0;
        set<int> lines;

        while ((pos = paragraphCopy.find(e, pos)) != std::string::npos) {
            counter++;

            for (int i = 0; i < (int)breakLinesPosition.size(); i++) {
                if ((int)pos < breakLinesPosition[i]) {
                    lines.emplace(begin + i);
                    break;
                }
            }

            if (lines.size() == 0) lines.emplace(begin);

            pos += (int)e.size();
        };
        if (counter != 0) {
            expressionsInParagraph.emplace(e);
            auto &info = expressionsInfoInParagraph[e];
            info.cont = counter;
            info.lines = lines;
            info.acents = acentos;

            expressionsInFullText.emplace(e);

            auto &infoText = expressionsInfo[e];
            infoText.cont += counter;
            infoText.acents = acentos;

            infoText.lines.insert(lines.begin(), lines.end());
        }
    }

    showExpressionInformation(outputFile, expressionsInParagraph,
                              expressionsInfoInParagraph);

    linesCounter++;

    paragraphs++;
    end = linesCounter;

    ParagraphInfo info;
    info.paragraph = paragraphs;
    info.begin = begin;
    info.sentence = sentences;
    info.words = words;
    info.wordsWithoutStopWords = words - stopWords;

    paragraphsInfo.push_back(info);

    showSentenceInformation(outputFile, &wordsInSentence, &wordsInfoInSentence,
                            words, stopWords);

    showHeader(outputFile, "FULL RESULT");

    showFullTextInformation(outputFile, &wordsInFullText, &wordsInfoInFullText);

    showSentenceDetails(outputFile, &sentencesInfo);

    showParagraphsDetails(outputFile, &paragraphsInfo);

    showExpressionInformation(outputFile, expressionsInFullText,
                              expressionsInfo);

    showHeader(outputFile, "END PROCESS");

    fclose(file);  // fecha o arquivo de entrada

    endExe = clock();
    execution_time = ((double)(endExe - startExe)) / CLOCKS_PER_SEC;

    fprintf(outputFile, "Time taken to execute in seconds : %f",
            execution_time);

    printf("Time taken to execute in seconds : %f", execution_time);

    fclose(outputFile);

    return 0;
}
