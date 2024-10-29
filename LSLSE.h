#ifndef LSLSE_H
#define LSLSE_H
template<class T>
class LSLSE;
#include <string>

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    
    void imprimirNodo(node<T>* nodo) const;
    void insertarCola(node<T>* nodoUltimo, T elem);

};

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> "<<std::endl;
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
void LSLSE<T>::insertarCola(node<T>* nodoUltimo, T elem) {
    node<T>* aux = new node<T>;  
    aux->data = elem;            
    aux->sig = nullptr;
    if (nodoUltimo == nullptr) { 
        if (lista == nullptr) { 
            lista = aux;
        } else {
            node<T>* temp = lista;
            while (temp->sig != nullptr) {
                temp = temp->sig;}
            temp->sig = aux; 
        }
    } else {
        aux->sig = nodoUltimo->sig; 
        nodoUltimo->sig = aux;}
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

//


/*template<class T>
node<T>* LSLSE<T>::buscarPorA(const std::string& text) const {
    node<T>* aux = lista; 
    while (aux != nullptr) {
        if (aux->data.gettext() == domicilio) { 
            return aux; 
        }
        aux = aux->sig; 
    }
    return nullptr; 
}*/

/*template<class T>
node<T>* LSLSE<T>::buscarPorB(int num) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        // Comparando con el número de socio
        if (aux->data.getnum() == numeroSocio) {
            return aux; 
        }
        aux = aux->sig; 
    }
    return nullptr;
}*/

template<class T>
void LSLSE<T>::imprimirNodo(node<T>* nodo) const {
    if (nodo != nullptr) { 
        std::cout << nodo->data << std::endl;
    } 
}

#endif // LSLSE_H



