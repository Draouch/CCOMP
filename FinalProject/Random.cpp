#include "Random.h"
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
T template_random(const T a){

    return a;

}

int generarRandom(int num){

    int randomNumero = rand();
    return template_random<int>((randomNumero % num) + 1);

}
