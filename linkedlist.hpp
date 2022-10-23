template<typename t>
class linkedlist;

template<typename t>
ostream& operator<<  (ostream&out , linkedlist<t> &lista);

template<class t>
class linkedlist{
private:
    node<t>*head;
    node<t>*fin;
    int size;
public:
    linkedlist();
    ~linkedlist();
    int getSize();//Nos da el tamaño
    node<t>* getHead();//Retorna el begin o head de la lista
    node<t>* getfin();//Retorna el fin de la lista
    void pushfront(t);//Inserta al inicio
    void pushend(t);//Inserta al final
    void push(int, t);//Inserta elemento segun posicion
    void popfront();//Eliimina al inicio
    void popend();//Elimina al final
    void eliminar(int);//Elimina elemento segun posicion
    void inserorden(t);//Inserta en ordenvoid push(int, t);//Inserta elemento segun posicion
    void remover(t);//Elimina segun elemento
    friend ostream& operator<< <> (ostream& , linkedlist<t> &); //Ssobrecarga de operador <<
    bool search(t);//Busca el elemento


    class Iterator{
        node <t>*nodolista;
     public:
        Iterator(){}
        bool operator != (node<t>* o)
        {
            return (nodolista != o);
        }
        Iterator& operator=(node<t> *igual)
        {
            nodolista=igual;
            return *this;
        }
        Iterator& operator ++()
        {
            nodolista=nodolista->getNext();
            return *this;
        }

        t getvalor(){return (nodolista->getValor());}

    };


};

template <typename t>
linkedlist<t>::linkedlist(){
    size=0;
    head=NULL;
    fin=NULL;
}

template <typename t>
void linkedlist<t>::pushfront(t ele){
    node<t>*nuevo=new node<t>(ele);
    node<t>*aux=head;
    if(!head){
        head=nuevo;
    }
    else{
        nuevo->setNext(head);
        head=nuevo;
        while(aux){
            aux=aux->getNext();
        }
    }
    size++;
}

template <typename t>
void linkedlist<t>::popfront(){
    node<t>*aux=head;
    node<t>*aux1;

    if(!head){
        cout<<"No se puede remover"<<endl;

    }
    else{
        head = aux->getNext();
        aux1=aux;
        delete aux1;
        size--;
        while(aux){
            aux=aux->getNext();
        }
    }
}

template <typename t>
void linkedlist<t>::popend(){
    node<t>*aux=head;
    node<t>*aux1;

    if(!head){
        cout<<"No se puede remover"<<endl;

    }
    else{
         while(aux->getNext()){
            aux=aux->getNext();
        }
        aux1=aux;
        delete aux1;
        size--;
    }

}

template <typename t>
void linkedlist<t>::pushend(t ele){
    node<t>*nuevo=new node<t>(ele);
    node<t>*aux=head;
    if(!head){
        head=nuevo;
    }
    else{
        while(aux->getNext()){
            aux=aux->getNext();
        }

        aux->setNext(nuevo);

    }
    size++;
}

template <typename t>
void linkedlist<t>::inserorden(t ele){
    node<t>*nuevo=new node<t>(ele);
    node<t>*aux=head;
    if(!head){
        head=nuevo;
    }
    else{
        if(head->getValor()>ele){
            nuevo->setNext(head);
            head=nuevo;
        }
        else{
            while((aux->getNext()!= NULL)&&(aux->getNext()->getValor()<ele)){
                aux=aux->getNext();
            }
            nuevo->setNext(aux->getNext());
            aux->setNext(nuevo);
        }
    }
    size++;
}

template <typename t>
void linkedlist<t>::remover(t ele){
    node<t>*aux=head;
    node<t>*aux1;
    int contador=0;

    for(int i=0;i<size;i++){
        if(aux->getValor()==ele){
            //eliminar

            break;
        }else{
            aux1=aux;
            aux=aux->getNext();
            contador++;
        }
    }
    if(contador==size){
        cout<<"No existe"<<endl;
    }else{
        if(contador==0){
            head=aux->getNext();

            delete aux;
        }
        aux1->setNext(aux->getNext());
        delete aux;
        size--;
    }
}

template <typename t>
void linkedlist<t>::eliminar(int pos){
    node<t>*aux=head;
    node<t> *aux1 = aux->getNext();

    if (pos < 1 || pos > size) {
        cout << "Fuera de rango " << endl;
    }
    else if (pos == 1) {
        head = aux->getNext();
    }
    else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                node <t>*aux2 = aux1;
                aux->setNext(aux1->getNext());
                delete aux2;
                size--;
            }
            aux = aux->getNext();
            aux1 = aux1->getNext();
        }
    }
}

template <typename t>
void linkedlist<t>::push(int pos, t ele){
    node<t>*nuevo=new node<t>(ele);
    node<t>*aux=head;
    node<t>*aux1=aux->getNext();
    if(pos < 1 || pos > size){
        cout << "Fuera de rango " << endl;
    }
    else if(pos==1){
        nuevo->setNext(head);
        head=nuevo;
        while(aux){
            aux=aux->getNext();
        }
    }
    else{
         for (int i = 2; i <= pos; i++) {
            if (i == pos) {

                aux->setNext(nuevo);
                nuevo->setNext(aux1);
                aux1=nuevo;
                size++;
            }
            aux=aux->getNext();
            aux1=aux1->getNext();
            }
        }
    }

template <typename t>
bool linkedlist<t>::search(t ele){
    node<t>*aux=head;
    node<t>*aux1;
    int contador=0;
    for(int i=0;i<size;i++){
        if(aux->getValor()==ele){
            return true;
            }else{
            aux1=aux;
            aux=aux->getNext();
            contador++;}
    }
        if(contador==size){
        return false;
        }else{
        return true;
    }
}

template <typename t>
int linkedlist<t>::getSize(){
    return size;
}

template <typename t>
node<t>* linkedlist<t>::getHead(){
    return head;
}

template <typename t>
node<t>* linkedlist<t>::getfin(){
    return fin;
}

template <typename t>
ostream & operator << (ostream& out, linkedlist<t> &lista){
    node<t>*aux=lista.getHead();
    for(int i=0;i<lista.getSize()-1;i++){
        out <<*aux<<" ";
        aux=aux->getNext();
    }
    out <<*aux<<" ";
    return out;
}

template <typename t>
linkedlist<t>::~linkedlist(){
    node<t>* aux;
    for(int i=0;i<size;i++){
        aux=head;
        head=head->getNext();
        delete aux;
    }
}
