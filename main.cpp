#include <iostream>
#include "ClassInvertedIndex.h"
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream f,c;
    ofstream k;
    char command[11];
    char input[50];
    ClassInvertedIndex tree;
    c.open("commands.txt",ios::in);
    k.open("output.txt",ios::out);
     bool done=false;
    int a,b;
    c>>command>>input;
    f.open(input,ios::in);
    while(!f.eof())
    {
        f>>a>>b;
        tree.neos(tree.root,a,b);
    }
    while(!done)
     {
         c>>command>>a>>b;
         if(strcmp("INSERT_LINK",command)==0)
         tree.neos(tree.root,a,b);
         else
            if(strcmp("DELETE_LINK",command)==0)
            tree.deleteboth(tree.root,a,b);
        else
            if(strcmp("WRITE_INDEX",command)==0)
            {
            tree.writeindex(tree.root,k);
            done=true;
            }
     }
    return 0;
}

