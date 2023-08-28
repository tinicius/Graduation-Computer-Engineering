#include "output_functions.hpp"

void showHeader(FILE *outputFile, string title) {
    fprintf(
        outputFile,
        "======================================================================"
        "================================================================\n");
    fprintf(outputFile,
            "=>                                                    ### ");
    fprintf(outputFile, "%s", title.c_str());
    fprintf(outputFile,
            " ###                                                          \n");
    fprintf(
        outputFile,
        "======================================================================"
        "================================================================\n\n");
};

void showSentenceInformation(FILE *outputFile, set<string, locale> *wordsInParagraph,
                             unordered_map<string, WordInfo> *wordAndFrequency,
                             int words, int stopWords) {
    if (wordAndFrequency->size() == 0) return;

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "________________________________________________________________\n");

    fprintf(outputFile, "%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n", 32, "WORD", 32,
            "PARAGRAPH", 32, "SENTENCE", 32, "LINE", 32, "APPEARANCES", 32,
            "POSITIONS", 32, "DISTÂNCIAS");

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-------------------------------------------------------------"
        "---\n");

    string output;

    for (auto &w : (*wordsInParagraph)) {
        auto &info = (*wordAndFrequency)[w];

        // Palavra
        fprintf(outputFile, "%-*s", 32 + info.acents, w.c_str());

        // Mostrando paragráfo
        fprintf(outputFile, "%-*s", 32,
                to_string(*info.paragraphs.begin()).c_str());

        // Mostrando sentenças
        for (auto i : info.sentence) output = to_string(i) + " " + output;
        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Linhas
        for (auto i : info.line) output = to_string(i) + " " + output;
        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Frequência
        fprintf(outputFile, "%-*s", 32, to_string(info.freq).c_str());

        // Mostrando posições
        for (auto i : info.positions) output += to_string(i) + " ";
        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Mostrando distâncias
        for (int i = 1; i < (int)info.positions.size(); i++) {
            int distancia = info.positions[i] - info.positions[i - 1] - 1;

            output = to_string(distancia) + " " + output;
        }

        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        fprintf(outputFile, "\n");
    }

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "________________________________________________________________\n");

    fprintf(outputFile, "=> Number of words with stop words: %d", words);
    fprintf(outputFile,
            "                                                     %-s%d\n",
            "=> Number of words without stop words: ", words - stopWords);

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-------------------------------------------------------------"
        "---\n\n");
};

void showParagraphBeginningAndSentences(FILE *outputFile, int beginParagraph,
                                        int sentences) {
    fprintf(
        outputFile,
        "======================================================================"
        "================================================================\n");

    fprintf(outputFile,
            "=> Beginning paragraph in line: %d  Number of sentences: %d\n",
            beginParagraph, sentences);

    fprintf(
        outputFile,
        "======================================================================"
        "================================================================\n");
};

void showFullTextInformation(
    FILE *outputFile, set<string,locale> *wordsInFullText,
    unordered_map<string, WordInfo> *wordsInfoInFullText) {
    if (wordsInFullText->size() == 0) return;

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "________________________________________________________________\n");

    fprintf(outputFile, "%-*s%-*s%-*s%-*s%-*s%-*s\n", 32, "WORD", 32,
            "PARAGRAPH", 32, "SENTENCE", 32, "LINE", 32, "APPEARANCES", 32,
            "POSITIONS");

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-------------------------------------------------------------"
        "---\n");

    for (auto &w : (*wordsInFullText)) {
        auto &info = (*wordsInfoInFullText)[w];

        string output = "";

        // Palavra
        fprintf(outputFile, "%-*s", 32 + info.acents, w.c_str());

        // Paragráfos
        for (auto i : info.paragraphs) output = to_string(i) + " " + output;

        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Sentenças
        for (auto i : info.sentence) output = to_string(i) + " " + output;
        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Linhas
        for (auto i : info.line) output = to_string(i) + " " + output;
        fprintf(outputFile, "%-*s", 32, output.c_str());
        output = "";

        // Frequência
        fprintf(outputFile, "%-*s", 32, to_string(info.freq).c_str());

        // Posições
        for (auto i : info.positions) output = to_string(i) + " " + output;
        fprintf(outputFile, "%-*s", 32, output.c_str());

        fprintf(outputFile, "\n");
    }

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-----------------------------------------------------------------\n");
};

void showExpressionInformation(
    FILE *outputFile, set<string, locale> &expressions,
    unordered_map<string, ExpressionInfo> &expressionsInfoInParagraph) {
    if (expressions.empty()) return;

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "________________________________________________________________\n");

    fprintf(outputFile, "%-*s %-*s %-*s\n", 32, "EXPRESSION", 32, "LINE", 32,
            "APPEARANCES");

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-------------------------------------------------------------"
        "---\n");

    for (auto w : expressions) {
        auto &info = expressionsInfoInParagraph[w];
        w.erase(w.begin());

        string lines = "";
        for (int i : info.lines) lines += to_string(i) + " ";

        for (int i = 0; i < info.acents; i++) fprintf(outputFile, "a ");

        fprintf(outputFile, "%-*s%-*s%-*s\n", 33, w.c_str(), 33, lines.c_str(),
                32, to_string(info.cont).c_str());
    };

    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-------------------------------------------------------------"
        "---\n");
}

void showSentenceDetails(FILE *outputFile,
                         vector<SentenceInfo> *sentencesInfo) {
    fprintf(
        outputFile,
        "______________________________________________________________________"
        "_________________________________________________________________\n");
    fprintf(
        outputFile,
        "                                       NUMBER OF WORDS IN EACH "
        "SENTENCE WITH AND WITHOUT STOP WORDS                                  "
        "  \n");
    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-----------------------------------------------------------------\n");

    for (auto &info : *sentencesInfo) {
        fprintf(
            outputFile,
            "Paragraph: %d	 Sentence: %d	 Number of words with stop "
            "words: %d	               Number of words without stop words: "
            "%d\n",
            info.paragraph, info.sentence, info.words,
            info.wordsWithoutStopWords);
    };

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "_________________________________________________________________\n");
};

void showParagraphsDetails(FILE *outputFile,
                           vector<ParagraphInfo> *paragraphsInfo) {
    fprintf(
        outputFile,
        "______________________________________________________________________"
        "_________________________________________________________________\n");
    fprintf(
        outputFile,
        "                                                   LINE NUMBER THAT "
        "START EACH PARAGRAPH                                               "
        "\n");
    fprintf(
        outputFile,
        "----------------------------------------------------------------------"
        "-----------------------------------------------------------------\n");

    for (auto &info : *paragraphsInfo) {
        fprintf(outputFile,
                "Paragraph: %d	 Beginning in line: %d	  Number of sentences: "
                "%d\n",
                info.paragraph, info.begin, info.sentence);
    }

    fprintf(
        outputFile,
        "______________________________________________________________________"
        "_________________________________________________________________\n");
}
