#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "entities.hpp"

#include <string>
#include <set>
#include <unordered_map>
#include <locale>

using namespace std;

void showHeader(FILE *outputFile, string title);

void showSentenceInformation(FILE *outputFile, set<string, locale> *wordsInParagraph, unordered_map<string, WordInfo> *wordAndFrequency, int words, int stopWords);

void showParagraphBeginningAndSentences(FILE *outputFile, int beginParagraph, int sentences);

void showFullTextInformation(FILE *outputFile, set<string,locale> *wordsInFullText, unordered_map<string, WordInfo> *wordsInfoInFullText);

void showExpressionInformation(FILE *outputFile, set<string, locale> &expressions, unordered_map<string, ExpressionInfo> &expressionsInfoInParagraph);

void showSentenceDetails(FILE *outputFile, vector<SentenceInfo> *sentencesInfo);

void showParagraphsDetails(FILE *outputFile, vector<ParagraphInfo> *paragraphsInfo);

#endif