#include <iostream>
#include <vector>
using namespace std;



void impriC(Conjunto *arr,string c1,string c2,int tam){

for(int i = 0; i<tam;i++){

if(arr[i].getNombre() == c1 || arr[i].getNombre() == c2 ){
    cout<<arr[i].getDatos();
    cout<<"  ";
}
}
cout<<endl;
}
void imprirlistaC(Conjunto *arr,int tam){
for(int i = 0; i<tam;i++){
    cout<<arr[i].getDatos();
    cout<<"  ";
}
cout<<endl;
}

//encuentra el indice de un objeto en un array con el nombre del objeto
int encontrarindice(Conjunto *arr, string Narre,int tam){
int indice;
for(int i = 0;i<tam;i++){
    if(arr[i].getNombre() == Narre){
        indice = i;
        break;
    }
}
return indice;
}


//elimina los elementos que contenga la palabra REP que se abrevia como que estaba repetido en el vector
void eliminarElemento(vector <string> &vec){

    for(int i = 0; i<vec.size(); i++) {
            if(vec.at(i) == "REP") {
                  vec.erase(vec.begin() + i);
                  i--;
            }
      }
}





//encuentra los elementos que se repiten de un vector y los remplaza por la palabra "REP"
void encontrarRepetidos(vector <string> &vec,int n){
  for(int i = 0; i <n; i++) {
            for(int j = i+1; j<n; j++) {
                  if(vec.at(i) == vec.at(j)) {
                        vec[j] = "REP";
                  }
            }
      }


}
