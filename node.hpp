template <typename t>
class node{
    t valor;
    node<t>*next;
public:
    node();
    node(t);
    void setValor(t);
    t getValor();
    void setNext(node<t>*);
    node<t>* getNext();

    ~node();
};

template <typename t>
node<t>::node(){
    valor=NULL;
    next=NULL;
}

template <typename t>
node<t>::node(t ele){
    valor=ele;
    next=NULL;
}

//Modifica
template <typename t>
void node<t>::setValor(t valor){
    this->valor=valor;
}


//Accede
template <typename t>
t node<t>::getValor(){
    return valor;
}

template <typename t>
void node<t>::setNext(node<t>*next){
    this->next=next;
}

template <typename t>
node<t>* node<t>::getNext(){
    return next;
}
template <typename t>
ostream & operator << (ostream &out, node<t> &nd){
    out <<"nodo: "<< nd.getValor();
    return out;
}

template <typename t>
node<t>::~node(){
    //cout<<"elim"<<endl;
}
