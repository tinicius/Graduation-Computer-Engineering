#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <set>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct WordInfo {
    int freq;
    int acents;
    unordered_set<int> paragraphs;
    unordered_set<int> sentence;
    unordered_set<int> line;
    vector<int> positions;
};

struct SentenceInfo {
    int sentence;
    int paragraph;
    int words;
    int wordsWithoutStopWords;
};

struct ParagraphInfo {
    int paragraph;
    int begin;
    int sentence;
    int words;
    int wordsWithoutStopWords;
};

struct ExpressionInfo {
    string text;
    int cont;
    int acents;
    set<int> lines;  // TODO: try change to unordered
};

#endif