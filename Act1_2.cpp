//Equipo 8: Fernanda Monserrat Galvan Romero - A00344712 & Jorge Daniel Cruz Case - A01634536
//Codigo donde se ejecutan los casos de prueba en matrices no ordenadas para su ordenamiento y busqueda
//Algoritmos de Busqueda y Ordenamiento
//10/09/2020
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
/*Para compilar: 
  g++ -std=c++17 *.cpp
 
  Para ejecutar:
  ./a.out  

*/


//Función para la lectura de los textos
//Complejidad total: O(1) o constante
void cargaDatos(vector<int>& b, string doc){
    ifstream archivo;
    archivo.open(doc);
    char tipo;
    int i = 0;
    if (archivo.is_open()){//Complejidad: O(1)
        string linea;
        while(getline(archivo,linea)){//Complejidad: O(1) 
            b.push_back(stoi(linea)); 
            i++;
        }      
        archivo.close();
    }
    else{
        cout<< "Error de lectura de archivo"<<endl;
    }

}

//Función para imprimir el vector
//Complejidad total: O(n)
void printVector(vector<int> a){
    for (int i=0;  i <a.size();  i++){// Si tomamos "a.size()" como "n" la complejidad es O(n)
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


//Algoritmo de ordenamiento por intercampio (Swap Sort)
//Complejidad total = O(n^2)
//Casos: mejor, promedio y peor = O(n^2)
int ordenaIntercambio(vector<int>& a){//Añadimos las complejidades: O(n)*O(n) = O(n^2)
    int intercambio = 0;
    int comparaciones = 0;
    cout<<"\nSe utilizo el algoritmo de SwapSort"<<endl;
    cout<<"\nArreglo ordenado: ";
    for(int i = 0; i<a.size(); i++){// Si tomamos "a.size()" como "n" la complejidad es O(n)
        for(int j = i+1; j<a.size(); j++){// Si tomamos "a.size()" como "n" la complejidad es O(n)
            comparaciones++;
            if(a[i]>a[j]){ //Complejidad O(1)
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
                intercambio++;
            }
        }
    }
    printVector(a);
    cout<<"\nNumero de Comparaciones: "<<comparaciones;
    return intercambio;
}

//Algoritmo de ordenamiento por burbuja (Bubble Sort)
//Complejidad total = O(n^2)
//Casos: mejor, promedio y peor = O(n^2)
int ordenaBurbuja(vector<int>& a){//Añadimos las complejidades: O(n)*O(n) = O(n^2)
    int intercambio = 0;
    int comparaciones = 0;
    cout<<"\nSe utilizo el algoritmo de BubbleSort"<<endl;
    cout<<"\nArreglo ordenado: ";
    for(int i = 0; i<a.size(); i++){// Si tomamos "a.size()" como "n" la complejidad es O(n)
        for(int j = 0; j<a.size()-i-1; j++){// Si tomamos "a.size()" como "n" la complejidad es O(n)
            comparaciones++;
            if(a[j]>a[j+1]){//Complejidad O(1)
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 
                intercambio++;
            }
        }
    }
    printVector(a);
    cout<<"\nNumero de Comparaciones: "<<comparaciones;
    return intercambio;
}
//La complejidad es de O(n)
void merge(vector<int>& a, int low, int mid, int high, vector<int>& s) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
  
    for (i = 0; i < n1; i++){
        left[i] = a[low + i]; 
    }
        
    for (j = 0; j < n2; j++){
        right[j] = a[mid + 1 + j];
    }
     
    i = j = 0; 
    k = low;
    while (i < n1 && j < n2) {
        s[0]++;
        if (left[i] <= right[j]) {
            s[1]++;
            a[k] = left[i];
            i++;
        }
        else {
            s[1]++;
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        s[1]++;
        a[k] = left[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        s[1]++;
        a[k] = right[j];
        j++;
        k++;
  }
}

//Algoritmo de ordenamiento por fusion (Merge Sort)
//Complejidad total: O(n log(n)) 
//Casos: mejor, promedio y peor = O(n log(n))
void ordenaMerge(vector<int>& a, int low, int high,vector<int>& s) { 
    if (low >= high) {
        return; 
    }
    int m = low + (high - low)/2;
    //Complejidad temporal de las recursiones: O(n^d) para a,b,d > 0
    ordenaMerge(a, low, m, s);    // mitad izquierda
    ordenaMerge(a, m+1, high,s); // mitad derecha
    merge(a, low, m, high, s);  // fusion de mitades
    //Si expresamos su relacion de recurrencia: T(n) = aT([n/b])+O(n^d)
    //Cuando resolvemos la relacion de recurrencia nos queda = O(n log(n))
    
}

//Algoritmos para la busqueda binaria
//Complejidad O(log2 (n)) utilizando la complejidad temporal promedio
//Caso: Worst(n) = log2(n+1)ϵ O(log n)
int busquedaBinaria(vector<int>& a,int k) {
    int n = a.size();
    int inf = 0;
    int sup = n - 1;
    int comparaciones = 0;
    while (inf <= sup) {
        int m = inf + (sup - inf) / 2;
        comparaciones++;
        if (k == a[m]) {
            cout << "\n--> Busqueda binaria\n" << endl;
            cout<<"Numero de Comparaciones: "<<comparaciones << endl;
            return m;
        }
        else if (k < a[m]) {
            sup = m - 1;
        }
        else {
        inf = m + 1;
        }
    }
    cout << "\n--> Busqueda Binaria\n" << endl;
    cout<<"Numero de Comparaciones: "<<comparaciones << endl;
    return -1;  
}

//Algoritmo para busqueda secuencial para arreglos ordenados
//Complejidad total: O(n)
//Casos: Best(n) = 1; Worst(n) = n/2
int busquedaSecuencialOrd(vector<int>& a, int k) {
  int n = a.size();
  int comparaciones = 0;
    for (int i=0; i < n; i++) {//Complejidad: O(n)
        comparaciones++;
        if (k <= a[i]) {//Complejidad: O(1)
            if (k == a[i]){//Complejidad: O(1)
                cout << "\n--> Busqueda secuencial\n" << endl;
                cout<<"Numero de Comparaciones: "<<comparaciones << endl;
                return i;
            } 
            else{//Complejidad: O(1)
                return -1;
                cout << "\n--> Busqueda secuencial\n" << endl;
                cout<<"Numero de Comparaciones: "<<comparaciones << endl;
            } 
        }
    }      
    return -1;
}


int main(){
    //Vectores iniciales
    vector <string> textos{"test01.txt","test02.txt","test03.txt","test04.txt"};
    vector<int> b{};
    vector<int> solucion{0,0};
    //Valores iniciales
    int numCompara = 0;
    int opcionOrd;
    int opcionBusq;
    int numeroBusq;
    int tamanio;
    int intercambio, intercambio2, intercambio3;
    for (int i =0; i < 4; i++){
        cout<<"\n----------------Caso de prueba "<<i+1<<"----------------"<<endl;
        b.erase(b.begin(), b.begin()+b.size());
        cargaDatos(b, textos[i]);
        tamanio = b[0]; //Lectura de linea 1 (tamaño)
        opcionOrd = b[1];//Lectura de linea 2 (eleccion de algoritmo de ordenamiento)
        opcionBusq= b[2];//Lectura de linea 3 (eleccion de algoritmo de busqueda)
        numeroBusq = b[3];//Lectura de linea 4 (numero a buscar)
        tamanio = b.size();
        b.erase(b.begin()+0);
        b.erase(b.begin()+0);
        b.erase(b.begin()+0);
        b.erase(b.begin()+0);
        
        cout<< "\nTamanio del arreglo: " <<tamanio<< endl;
        if (opcionOrd==1){
            intercambio = ordenaIntercambio(b);
            cout << "\nNumero de intercambios realizados: " <<intercambio << endl;

        }
        else if (opcionOrd == 2){
            intercambio2 = ordenaBurbuja(b);
            cout << "\nNumero de intercambios realizados: " <<intercambio2 << endl;
        }
        else{
            //Se manda a llamar al algoritmo Merge, con low y high siendo la primera y ultima posicion respectivamente
            ordenaMerge(b,0,tamanio-5, solucion);
            cout<<"\nArreglo ordenado: ";
            printVector(b);
            cout << "\nNumero de comparaciones: " << solucion[0] << endl;
            cout << "Numero de intercambios realizados: " << solucion[1] << endl;
        }
        if (opcionBusq==1){
            //Algoritmo de busqueda binaria, linea 3 es igual a 1
            int bus = busquedaSecuencialOrd(b, numeroBusq);
            if(bus==-1){
                //El algoritmo regresa -1 si no se encontro el numero en el arreglo
                cout << "El numero "<< numeroBusq << " no esta en el arreglo" << endl;
            }
            else{
                //El algoritmo regresa la posicion del numero en el arreglo
                cout << "El numero "<< numeroBusq << " esta en al posicion: " << bus << " del arreglo\n" << endl;
            }
        }
        else{
            //Algoritmo de busqueda binaria, linea 3 es igual a 2
            int resultado_busqueda = busquedaBinaria(b, numeroBusq);
            if(resultado_busqueda==-1){
                //El algoritmo regresa -1 si no se encontro el numero en el arreglo
                cout << "El numero "<< numeroBusq << " no esta en el arreglo" << endl;
            }
            else{
                //El algoritmo regresa la posicion del numero en el arreglo
                cout << "El numero "<< numeroBusq << " esta en al posicion: " << resultado_busqueda << " del arreglo\n" << endl;
            }
        }
    }
    return 0;
}