#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node {
    char ch;
    int fq;
    node* lchild;
    node* rchild;
};

struct table {
    char ch;
    string code;
};

void preSearch(node* T, string code, vector<table>& t)
{
    if (T) {
        if (T->ch) {
            table tab;
            tab.ch = T->ch;
            tab.code = code;
            t.push_back(tab);
        }
        preSearch(T->lchild, code + "0", t);
        preSearch(T->rchild, code + "1", t);
    }
}

bool operator<(node i, node j) { return (i.fq > j.fq); }

int main(int argc, char const* argv[])
{
    priority_queue<node> q;
    string s;
    // while (getline(cin, s)) {
    //     node* n = new node();
    //     sscanf(s.c_str(), "%c %d", &n->ch, &n->fq);
    //     n->lchild = nullptr;
    //     n->rchild = nullptr;
    //     q.push(*n);
    // }

    // while (q.size() > 1) {
    //     node n;
    //     node* lc = new node();
    //     node* rc = new node();
    //     *lc = q.top();
    //     q.pop();
    //     *rc = q.top();
    //     q.pop();
    //     n.lchild = lc;
    //     n.rchild = rc;
    //     n.ch = 0;
    //     n.fq = lc->fq + rc->fq;
    //     q.push(n);
    // }

    // node hfmtree = q.top();
    // q.pop();

    // vector<table> hfmtable;
    // preSearch(&hfmtree, "", hfmtable);

    // fstream out("hfmtree.txt", ios::out);
    // for (int i = 0; i < hfmtable.size(); i++) {
    //     out << hfmtable[i].ch << ":" << hfmtable[i].code << endl;
    // }
    // out.close();

    fstream in("hfmtree.txt", ios::in);
    vector<table> hfmtable1;
    while (getline(in, s)) {
        char ch;
        char tmp[100];
        sscanf(s.c_str(), "%c:%s", &ch, tmp);
        string code(tmp);
        table tab;
        tab.ch = ch;
        tab.code = code;
        hfmtable1.push_back(tab);
    }
    in.close();

    getline(cin, s);
    string codeText = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < hfmtable1.size(); j++) {
            if (s[i] == hfmtable1[j].ch) {
                codeText += (hfmtable1[j].code + "  ");
                break;
            }
        }
    }
    cout << codeText << endl;

    system("pause");
    return 0;
}
