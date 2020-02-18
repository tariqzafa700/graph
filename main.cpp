#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Graph.h"
#include "DiGraph.h"
#include "WeightedGraph.h"
#include "EdgeParserImpl.h"
#include "EdgeParserWeightedImpl.h"

using namespace std;

stringstream getDataStream(const string& file)
{
    stringstream ss;
    ifstream inFile;
    inFile.open(file);
    string v, e;
    getline(inFile, v);
    ss << v << ' ';
    getline(inFile, e);
    ss << e << ' ';
    for (int i = 0; i < atoi(e.c_str()); ++i)
    {
        string verts;      
        getline(inFile, verts);
        std::regex words_regex("[^\\s]+");
        auto words_begin = std::sregex_iterator(verts.begin(), verts.end(), words_regex);
        auto words_end = std::sregex_iterator();
        for_each(words_begin, words_end, [&ss](smatch vert) {
            ss << vert.str() << ' ';
        });
    }
    return ss;
}

int main()
{
    
    auto ss = getDataStream("../input.txt");
    DiGraph graph2(ss, EdgeParserImpl());
    graph2.init();
    graph2.print();

    ss = getDataStream("../weighted-input.txt");
    WeightedGraph graph3(ss, EdgeParserWeightedImpl());
    graph3.init();
    graph3.print();
}