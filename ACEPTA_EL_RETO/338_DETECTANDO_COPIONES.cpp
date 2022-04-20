#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);

    unordered_set<int> examenes;
    unordered_multiset<int> hashTable;
    unordered_multiset<int>::iterator it;
    examenes.reserve(1000000);
    deque<int> examenesProfesor;
    int numExamenes, numRecordados, copiados, pillados, idExamen;

    while (scanf("%d %d", &numExamenes, &numRecordados) == 2) {

        copiados = pillados = 0;
        for (int i = 0; i < numExamenes; ++i) {
            scanf("%d", &idExamen);
            if (!examenes.insert(idExamen).second) ++copiados;

            it = hashTable.find(idExamen);
            if (it != hashTable.end()) ++pillados;
                 
            examenesProfesor.push_back(idExamen);
            hashTable.insert(idExamen);

            if (examenesProfesor.size() > numRecordados) {
                it = hashTable.find(examenesProfesor.front());
                if (it != hashTable.end()) hashTable.erase(it);
                examenesProfesor.pop_front();
            }            
        }

        printf("%d %d\n", copiados, pillados);
        examenes.clear();
        examenesProfesor.clear();
        hashTable.clear();
    }

    return 0;
}