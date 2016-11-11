#include <iostream>
#include "graph.cpp"

int main(){

    Graph gr({4, 4, 4, 6, 7}, {1, 2, 4, 8, 12});
    cout << gr.numOutgoing(4) << endl;

    return 0;
}
