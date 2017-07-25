#include<typeinfo>
#include <iostream>
using namespace std;

// MADE BY MATTIA BOTTARO

// lista di esercizi teorici in preparazione all'esame di p2, A.A. 15-16

// ESERCIZIO 3



/*

class A{
public:
    virtual void f(){cout<<1;};
};
class B: public A{
public:
    virtual void f(){cout<<2;}
};

main(){
    A* p=new B;
    p->f();
}

class D;

class B { public:
    virtual D* f() =0;
};

class C { public:
    virtual C* g();
    virtual B* h() =0;
};

class D: public B, public C {
public:
    D* f() {cout << "D::f "; return new D;}
    D* h() {cout << "D::h "; return dynamic_cast<D*>(g());}
};

C* C::g() {
    cout << "C::g ";
    B* p = dynamic_cast<B*>(this);
    if(p) return p->f();
    else return this;
}

class E: public D {
public:
    E* f() {
        cout << "E::f ";
        E* p = dynamic_cast<E*>(g());
        if(p) return p; else return this;
    }
};
class F: public E {
public:
    E* g() {cout << "F::g "; return new F;}
    E* h() {
        cout << "F::h "; E* p = dynamic_cast<E*>(E::g());
        if(p) return p;
        else return new F;
    }
};
B* p; C* q; D* r;
main(){
  //  p = new E; p->f();                      //AMBIGUA
    //q = new E; q->h();                      //AMBIGUA
  //  r = new E; r->f();                      //ERRORE
//    r = new F; r->h();                      //F::h  C::g  E::f  F::g
}
*/
/*
class A{

};
class B: public A{

};

main(){
    A* p=new B;
    A* p2=p;
    if(typeid(*p2)==typeid(A)) cout<<"1"; // stampa uno

}
*/
/*
class A {
public:
   A() { cout << "A ";}
   A(const A&) {cout << "Ac ";}
   virtual  ~A() {cout << " ~A ";}
};
class B : virtual public A {
public:
   B() { cout << "B "; }
   ~B() {cout << " ~B "; }
};
class C : virtual public A {
public:
   static A x;
   C() { cout << "C "; }
   C(const C&) {cout << "Cc ";}
   ~C() {cout << " ~C "; }
};

A C::x;

class D : public B, public C {
public:
   D() { cout << "D "; }
   D& operator=(const D& d) {cout << "D= "; return *this;}
   ~D() {cout << " ~D "; }
};
int main() {
   cout << "START" << endl;
   D *b=new D(); cout << "UNO" << endl;
   D d,e; cout << "DUE" << endl;
   e=d;cout << "TRE" << endl;
   return 0;
}
*/
/*
class A {
public:
   virtual void f(int x=0) { cout << "A::f(" << x << ")" << endl;}
};
class B : public A {
public:
   virtual void f(int x=1) { cout << "B::f(" << x << ")" << endl;}
};
int main() {
   A *p=new A;
   p->f();
   p=new B;
   p->f();
   B *q=new B;
   q->f();
   return 0;
}
*/
/*
class C {
public:
   C(int x=0,int y=1) {a[0]=x; a[1]=y; cout << "C(" << a[0] << "," << a[1] << ") ";}
   C(const C&) {cout << "Cc ";}
   int a[2];
};
class D {
public:
   D() : c2(&c1),cr(c1) { cout << "D() ";}
   D(const D& d) : cr(c1) { cout << "Dc ";}
   ~D() { cout << " ~D ";}
private:
   C c1;
   C *c2;
   C& cr;
};
class E {
public:
   static C cs;
};
   C E::cs=1;

int main() {
    cout<<endl;
   C c; cout << "UNO" << endl;
   C x(c); cout << x.a[0] << " " << x.a[1] << " DUE" << endl;
   D d=D(); cout << "TRE" << endl;
   E e;cout << "QUATTRO" << endl;
   return 0;
}
*/
/*
class C {
public:
   C(int n=1) : number(n) { cout << "C(" << number << ") "; }
   ~C() { cout << " ~C(" << number << ") "; }
   C& operator=(const C& c) { number=c.number; cout << "operator=(" << number << ") "; }
   int number;
};
int F(C c) {return c.number;}

int main() {
   C *c=new C; cout << "UNO" << endl;
   C d; d=*c; cout << "DUE" << endl;
   int x=F(d); cout << "TRE" << endl;
   int y=F(F(d)); cout << "QUATTRO" << endl;
   return 0;
}
*/
/*
using namespace std;
namespace ns {
class C {
public:
C(int n=0) : x(n) {}
private:
friend int f();
int x;
};
}
int f() {
ns::C c;
return c.x;
}
int main() {
f();
return 0;
}
*/
/*
class C {
public:
   C(int n=0) : number(n) { cout << "C(" << number << ") "; }
   ~C() { cout << " ~C "; }
   C(const C& c) : number(c.number) { cout << "Cc(" << number << ") "; }
   operator int() { cout << "int() "; return 3;}
private:
   int number;
};
int F(C c) {return c;}

int main() {
   C *c=new C; cout << "UNO" << endl;
   C d; cout << "DUE" << endl;
   int x=F(d); cout << "TRE" << endl;
   C e=F(d); cout << "QUATTRO" << endl;
   return 0;
}
*/
/*
class C {
public:
   C(int x=0,int y=1) {
   a[0]=x; a[1]=y; cout << "C(" << a[0] << "," << a[1] << ") ";
   }
   int a[2];
};
class D {
public:
   D() : c2(&c1),cr(c1) { cout << "D() ";}
   D(const D& d) : cr(c1) { cout << "Dc ";}
   ~D() { cout << "~D ";}
private:
   C c1;
   C *c2;
   C& cr;
};
class E {
public:
   static C cs;
};
C E::cs;
int main() {
    cout<<endl;
   C c; cout << "UNO" << endl;
   C x(c); cout << x.a[0] << " " << x.a[1] << " DUE" << endl;
   D d=D(); cout << "TRE" << endl;
   E e;
}
*/

class A{
protected:
    int x;
public:
    A(int k=0) : x(k) {cout<<"A(int)"<<x<<"| ";}
    ~A() {cout<<"~A ";}
    operator double() const {cout<<"operator double() "; return x;}
};

class B : public A{
public:
    static A a;
    const A &a2;
    A F(A a=A()) {return a;}
    B (int k=3, const A &a3=0) : A(k), a2(a3)  {cout<<"B() ";}
    ~B(){cout<<"~B ";}
    B(const B &b) : a2(b) {cout<<a2<<" ";}
};

A B::a(1);

int main(){
    cout<<endl;
    A a(1); cout<<"UNO"<<endl;
    B b; cout<<"DUE"<<endl;
    B b2(a); cout<<"TRE"<<endl;
    B b3(a,a); cout<<"QUATTRO"<<endl;
    B b4=b3; cout<<"CINQUE"<<endl;
    a=b.F(); cout<<"SEI"<<endl;
    b.F(2); cout<<"SETTE"<<endl;
}


/*
    COSA STAMPA compilando con -fno-elide-constructors

    allocazione varibili statiche -> A(int)
    A a(1) -> A(int) UNO
    B b -> A(int) A(int) B() ~A DUE
    B b2(a) -> operator double() A(int)0 A(int)1 B() ~A() TRE
    B b3(a,a) -> operator double() A(int)1 B() ~A() QUATTRO
    B b4=b3 -> A(int)0 operator double() 1 CINQUE
    b.F() -> A(int)0 ~A ~A ~A SEI
    b.F(2) -> A(int)2 ~A ~A ~A SETTE
    disutrozione variabili allocate -> ~B ~A ~B ~A ~B ~A ~B ~A ~A ~A

*/

/*
using namespace std;
class A{public: virtual ~A(){}};
class B: virtual public A{};
class C: virtual public A{};
class D: public B, public C{};
class E: public D{};
class F: public E{};
template<class T>
void fun(T& ref){
    bool b=0;
    B* p=&ref;
    try{throw ref;}
    catch(E){cout<<"E"; b=1;}
    catch(D){cout<<"D"; b=1;}
    catch(B){cout<<"B"; b=1;}
    catch(A){cout<<"A"; b=1;}
    catch(C){cout<<"C"; b=1;}
    if(b==0) cout<<"ZERO";
}
main(){
    A a; B b; C c; D d; E e; F f;
    A* pa=&b;D* pd=&f;
    B* pb = dynamic_cast<B*>(pa); C* pc=dynamic_cast<E*>(pd); E* pe= static_cast<E*>(pd);
    //fun(a); // non compila
    fun(b);cout<<endl; // B
   // fun(c);cout<<endl; // non compila
    fun(d);cout<<endl; // D
    fun(e);cout<<endl; // E
    fun(f);cout<<endl; // E
    // fun(*pa);cout<<endl; // NON COMPILA
    fun(*pb);cout<<endl; // B
    //fun(*pc);cout<<endl; // NON COMPILA
    fun(*pd);cout<<endl; // D
    fun(*pe);cout<<endl; // E
    fun<B>(*pd);cout<<endl; // B
    fun<D>(*pd);cout<<endl; // D
    //fun<E>(*pd);cout<<endl; // Non compila
}
*/
/*
 *
class Z {
public: Z(int x) {}
};

class A {
public:
   void f(int) {cout << "A::f(int) "; f(true);}
   virtual void f(bool) {cout <<"A::f(bool) ";}
   virtual A* f(Z) {cout <<"A::f(Z) "; f(2); return this;}
A() {cout <<"A() "; }
};

class B: virtual public A {
public:
   void f(const bool&){cout<< "B::f(const bool&) ";}
   void f(const int&){cout<< "B::f(const int&) ";}
   virtual B* f(Z) {cout <<"B::f(Z) "; return this;}
   virtual ~B() {cout << " ~B ";}
   B() {cout <<"B() "; }
};

class C: virtual public A {
public:
   C* f(Z){cout <<"C::f(Z) "; return this;}
   C() {cout <<"C() "; }
};

class D: public B {
public:
   virtual void f(bool) const {cout <<"D::f(bool) ";}
   B* f(Z) {cout << "D::f(Z) "; return this;}
   ~D() {cout <<"~D ";}
   D() {cout <<"D() "; }
};

class E: public D, public C {
public:
   void f(bool){cout<< "E::f(bool) ";}
   E* f(Z){cout <<"E::f(Z) "; return this;}
   E() {cout <<"E() "; }
   ~E() {cout <<"~̃E ";}
};
main(){
    cout<<"(";B* pb=new B; C* pc = new C; D* pd = new D; E* pe = new E; A *pa1=pb, *pa2=pc, *pa3=pd, *pa4=pe; B *pb1=pe;cout<<")";
    cout<<endl;cout<<endl;
    E* puntE=new E;cout<<endl; // A() B() D() C() E()
    D* puntD=new D;cout<<endl; // A() B() D()
    pa3->f(3);cout<<endl; // A::f(int) A::f(bool)
    pa4->f(3);cout<<endl;// A::f(int) E::f(bool)
    pb1->f(true);cout<<endl; // B::f(const bool&)
    pa4->f(true);cout<<endl; // E::f(bool)
    pa2->f(Z(2));cout<<endl; // C::f(Z)
    pa4->f(Z(2));cout<<endl; // E::f(Z)
    pb->f(3);cout<<endl; // B::f(const int&)
    pc->f(3);cout<<endl; // C::f(Z)
    (pa4->f(Z(3)))->f(4);cout<<endl; // E::f(Z) A::f(int) E::f(bool)
    (pc->f(Z(3)))->f(4);cout<<endl; // C::f(z) C::f(z)
    delete pa4;cout<<endl; // stampa nulla, il distruttore di A non è virtuale!
    delete pd;cout<<endl; // ~D ~B
}
*/
/*
// es slide 9-12-15
class A{
private:
    void h(){cout<<"A::h ";}
public:
    virtual void g(){cout<<"A::g ";}
    void f(){cout<<"A::f ";g();h();}
    void m(){cout<<"A::m ";g();h();}
    virtual void k(){cout<<"A::k ";g();h();m();}
    A* n(){cout<<"A::n "; return this;}
};

class B: public A{
private:
    void h(){cout<<"B::h ";}
public:
    virtual void g(){cout<<"B::g ";}
    void m(){cout<<"B::m ";g();h();}
    void k(){cout<<"B::k ";g();h();m();}
    B* n(){cout<<"B::n "; return this;}
};

int main(){
    B* b=new B(); // TS(b)=TD(b)=B*;
    A* a=new B(); // TS(a)=A*; TD(a)=B*;
    b->f(); cout<<endl; // A::f B::g A::h , non abbiamo una ridefinizione di f() in B -> viene chiamata quella di A
    b->m(); cout<<endl; // B::m B::g B::h
    b->k(); cout<<endl; // B::k B::g B::h B::m B::g B::h
    a->f(); cout<<endl; // A::f B::g A::h
    a->m(); cout<<endl; // A::m B::g A::h
    a->k(); cout<<endl; // B::k B::g B::h B::m B::g B::h
    (b->n())->g(); cout<<endl; // B::n B::g
    (b->n())->n()->g(); cout<<endl; // B::n B::n B::g
    (a->n())->g(); cout<<endl; // A::n B::g
    (a->n())->m(); cout<<endl; // A::n A::m B::g A::h
}
*/
/*
// es pagina 184
class B{
public:
    // overloading di m
    void m(int x){cout<<"B::m(int)"<<endl;}
    void m(int x,int y){cout<<"B::m(int,int)"<<endl;}
};
class D: public B{
public:
    using B::m; // dichiarazione d'uso. Se non viene trovata la funzione in D, si cerca in B
    //ridefinizione di m
    void m(int x){cout<<"D::m(int)"<<endl;}
    void m(){cout<<"D::m()"<<endl;}
};
int main(){
    D d;
    d.m(3); // D::m(int)
    d.m(); // D::m(), se non esistesse in D, verrebbe richiamata quella in B
    d.m(3,5); // B::m(int,int)
    d.B::m(4); // B::m(int)
}
*/
/*
//es pagina 183
class B{
protected:
    int x;
public:
    B():x(2){}
    void print(){cout<<x<<endl;}
};
class D: public B{
private:
    double x; // ridefinizione del campo dati x
public:
    D():x(3.14){}
    void print(){ // ridefinizione di print
        cout<<x<<endl;
    }
    void printAll(){
        cout<<B::x<<" "<<x<<endl;
    }
};
int main(){
    B b; D d;
    b.print(); // 2
    d.print(); // 3.14
    d.printAll(); // 2 3.14
}
*/
/*
//es pagina 180
class C{
public:
    int x;
    void f(){x=4;}
};
class D: public C{
public:
    int y;
    void g(){
        //C::x=0; // eventuale scooping. C::x è differente da x.
        x=5; y=6;
    }
};
class E: public D{
public:
    int z;
    void h(){
        x=7; y=8; z=9;
    }
};
int main(){
    C c; D d; E e;
    c.f(); d.g(); e.h();

    //PERICOLOSO
    D* pd=static_cast<D*>(&c); // abbiamo un puntatore di tipo D che punta ad un oggetto di tipo C
    cout<<pd->x<<" "<<pd->y<<endl; // pd punta ad un C. Ma un obj C non ha come capo dati y! Stampa di 4 e di un valore inatteso. → run-time error

    //PERICOLOSO
    E& re=static_cast<E&>(d); // abbiamo un riferimento di tipo E che è alias di un oggetto di tipo D
    cout<<re.x<<" "<<re.y<<" "<<re.z<<endl; // re è di tipo E ed alias di un obj di tipo D. Ma un obj di tipo D non ha come campo dati z.
    // stampa di 5 6 e valore inatteso. → errore run time

    C* pc=&d;
    pd=static_cast<D*>(pc); // ok perchè pc è un C* ma punta ad un D
    cout<<pd->x<<" "<<pd->y<<endl; // 5 6

    D& rd=e;
    E& s=static_cast<E&>(rd); // ok perchè rd è un D& ma alias di un E
    cout<<s.x<<" "<<s.y<<" "<<s.z<<endl; // 7 8 9
}
*/
/*
//es pagina 179
class C{
    friend void print(C);
private:
    int i;
public:
    C():i(1){}
};
void print(C x){cout<<x.i<<endl;}
class D: public C{
    friend void print(D);
private:
    double z;
public:
    D():z(3.14){}
};
void print(D x){cout<<x.z<<endl;}
int main(){
    C c; D d;
    print(c); // 1
    print(d); // 3.14
}
*/
/*
// es pagina 179
class C{
    friend class Z;
    friend void print(C);
private:
    int i;
public:
    C():i(1){}
};
class D: public C{
private:
    double z;
public:
    D():z(3.14){}
};
class Z{
public:
    void m(){
        C c; D d;
        cout<<c.i<<endl;
      //  cout<<d.z; → illegale
    }
};
int main(){
    Z z;
    z.m(); // 1
}
*/
/*
// es pagina 178
class C{
    friend void print(C); // le amicizie non si ereditano!
private:
    int i;
public:
    C():i(1){}
};
class D: public C{
private:
    double z;
public:
    D():z(3.14){}
};
void print(C x){
    cout<<x.i<<endl;
    D d;
  //  cout<<d.z; → illegale, le amicizie non si ereditano.
}
int main(){
    C c; D d;
    print(c); // 1
    print(d); // 1
}
*/
// prova sui template. Pagina 140 in poi
/** Definire una classe template Queue<T> che rappresenta una coda con nodi rappresentati
 *  dalla classe QueueItem<T>. Si dovrà popolarla e stamparla */
/*
class QueueItem; // dichiarazione incompleta
ostream& operator<<(ostream&,const QueueItem&);

template<class T> class Queue; // dichiarazione incompleta
template<class T> ostream& operator<<(ostream&,const Queue<T>&);

template<class T>
class Queue{
    friend class QueueItem;
    friend ostream& operator<< <T>(ostream&,const Queue<T>&); // ok compila, ma Qt Creator segna errore ortografico il "<T>"
private:
    class QueueItem{
        friend class Queue<T>; // per fare ciò ci serve la dichiarazione incompleta di Queue
        friend ostream& operator<<(ostream&,const QueueItem&); // ok compila, ma Qt Creator segna errore ortografico il "<T>"
        friend ostream& operator<< <T>(ostream&,const Queue<T>&);
    private:
        T info;
        QueueItem* next;
        QueueItem(const T& val):info(val),next(0){}
        QueueItem(int x,QueueItem* succ):info(x),next(succ){}
    };
    T dim;
    QueueItem* first; // puntatore al primo nodo della coda
    static QueueItem* crea(T);
public:
    Queue():dim(0),first(0){}
    Queue(T x):dim(x),first(crea(x)){}
};

template <class T>
QueueItem* Queue<T>::crea(T dim){
    if(dim)
        return new QueueItem(dim,crea(dim-1));
    return 0;
}
ostream& operator<<(ostream& os,QueueItem& p){
    os<<p.info<<" ";
    return os;
}
template<class T>
ostream& operator<<(ostream& os,const Queue<T>& p){
    QueueItem* L=p.first;
    for(;L;L=L->next) os<<*L<<" ";
    return os;
}

int main(){
    Queue<int> L(8);
    cout<<L;
}
*/
/*
// es pagina 144
class A{
public:
    A(int x=0){cout<<x<<"A() ";}
};

template <class T>
class C{
public:
   static A s;
};
// inizializzazione del campo statico s di tipo A
template<class T>
A C<T>::s=A();

int main(){
    // il costruttore di defaul standard non costruisce gli oggetti statici
    C<double> c;
    C<int> d;
    // qui lo costruiamo noi
    C<int>::s=A(2); // 0A() 2A() ...prima viene costruito s (e stampa 0A()), poi viene richiamato il costruttore con parametro 2
}
*/
/*
// es pagina 143
template<int I> // parametro valore
class C{
    static int numero;
public:
    C();
    void stampa_numero();
};
// inizializzazione del campo statico numero
template<int I>
int C<I>::numero=I;

template<int I>
C<I>::C(){numero++;} // costruttore

template<int I>
void C<I>::stampa_numero(){
    cout<<"Valore statico: "<<numero<<endl;
}

main(){
    C<1> uno;C<2> due_a,due_b;
    uno.stampa_numero(); // 2
    due_a.stampa_numero(); // 4
    //C<2> due_b; spostando la costruzione di due_b qui avremmo stampato 2 3 4
    due_b.stampa_numero(); // 4
}
*/
/*
// es pagine 140
template<class T>
class C{
    template<class V> // template non associato
    friend void fun(C<V>);
private:
    T x;
public:
    C(T y): x(y){}
};
template <class T>
void fun(C<T> t){
    cout<<t.x<<" ";
    C<double> c(3.1);
    cout<<c.x<<endl; // permesso dall'amicizia non associata
}
int main(){
    C<int> c(4);
    C<string> s("blob");
    fun(c); // 4 3.1
    fun(s); // blob 3.1
}
*/
/*
// es pagina 139
template<class T> class C; // dichiarazione incompleta del tempplate di classe C

template<class T>
void f_friend(C<T>);

template <class T>
class C{
    friend void f_friend<T>(C<T>);
private:
    T t;
public:
    C(T x):t(x){}
};
template <class T>
void f_friend(C<T> c){
    cout<<c.t<<endl; // per amicizia
}
int main(){
    C<int> c1(1); C<double> c2(2.5);
    f_friend(c1); // 1
    f_friend(c2); // 2.5
}
*/

// prova su contenitori ed iteratori. Pagina 85 in poi
/** gestire una lista. */
/*
class contenitore{
    friend class iteratore;
    friend ostream& operator<<(ostream& os,const contenitore&);
private:
    int dim;
    class nodo{ // di cosa è composto il contenitore
        friend class contenitore;
    private:
        int info;
        nodo* next;
    public:
        nodo():info(0),next(0){}
        nodo(int x):info(x),next(0){}
        nodo(int x,nodo* n):info(x),next(n){}
    };
    nodo* first; // puntatore al primo nodo del contenitore
public:
    class iteratore{ // funzionalità, iteriamo sui nodi del contenitore
        friend class contenitore; // contenitore deve poter accedere a punt che è privato
    private:
        contenitore::nodo* punt; // nodo puntato dall'iteratore, permesso dall'amicizia
    public:
         iteratore& operator++(); // overloading di incremento prefisso
         bool operator!=(const iteratore&) const;
    };
    static nodo* crea(int x);
    contenitore():dim(0),first(0){}
    contenitore(int x):dim(x),first(crea(x)){}
    iteratore begin() const,end() const;
    int& operator[](iteratore const&) const; // overloading di subscripting
};
contenitore::nodo* contenitore::crea(int x){
    if(x) return new nodo(x,crea(x-1));
    return 0;
}

contenitore::iteratore contenitore::begin() const{ // dato un contenitore, ne ritorna l'inizio
    iteratore tmp;
    tmp.punt=first; // permesso dall'amicizia
    return tmp;
}
contenitore::iteratore contenitore::end() const{
    iteratore tmp;
    tmp.punt=0; // permesso dall'amicizia
    return tmp;
}
int& contenitore::operator[](iteratore const& it) const{
    return it.punt->info; // permesso dall'amicizia con contenitore
}
contenitore::iteratore& contenitore::iteratore::operator++(){
    if(punt) punt=punt->next;  // permesso dall'amicizia con contenitore
    return *this;
}
bool contenitore::contenitore::iteratore::operator!=(const iteratore& it) const{
    return punt!=it.punt;  // permesso dall'amicizia con contenitore
}

ostream& operator<<(ostream& os,const contenitore& cont){
    for(contenitore::iteratore it=cont.begin();it!=cont.end();++it)
        os<<cont[it]<<" ";
    return os;
}

int main(){
    contenitore C(10);
    cout<<C;
}
*/

// es pagina 77
/*
class A{
private:
    int z;
public:
    ~A(){cout<<"Ad ";}
};
class B{
public:
    A* p;
    A a;
    ~B(){cout<<"Bd ";}
};
class C{
public:
    static B s;
    int k;
    A a;
    ~C(){cout<<"Cd ";}
};
B C::s=B(); // senza questa istruzione stamperemmo Cd Ad Cd Ad
int main(){
    C c1,c2;
}
*/
/*
// es pagina 77
class C{
public:
    string s;
    C(string x="1"):s(x){}
    ~C(){cout<<s<<"Cd ";}
};
C& F(C& p){return p;}
C w("3");
class D{
public:
    static C c;
};
C D::c("4");
main(){
    C x("5"),y("6");D d;
    y=F(x);cout<<"uno ";
    C z=F(x);cout<<"due ";
    // uno due 5Cd 5Cd 5Cd 4Cd 3Cd
}
*/
/*
// es pagina 76
class C{
public:
    string s;
    C(string x="1"):s(x){}
    ~C(){cout<<s<<"Cd ";}
};

C F(C& p){return p;}
C w("3");
class D{
public:
    static C c;
};
C D::c("4");
main(){
    C x("5"),y("6"); D d;
    y=F(x);cout<<"uno ";
    C z=F(x);cout<<"due ";
    // 5Cd uno 5Cd due 5Cd 5Cd 5Cd 4Cd 3Cd
}
*/
/*
// es pagina 76
class C{
public:
    string s;
    C(string x="1"):s(x){}
    ~C(){cout<<s<<"Cd ";}
};
C F(C p){return p;}
C w("3");
class D{
public:
    static C c;
};
C D::c("4");
int main(){
    C x("5");C y("6");D d;
    y=F(x); cout<<" uno ";
    C z=F(x); cout<<" due ";
    // 5Cd 5Cd uno 5Cd 5Cd due 5Cd 5Cd 5Cd 4Cd 3Cd
}
*/
/*
// es pagina 56
class C{
public:
    C(){cout<<"C0 ";}
    C(const C&){cout<<"Cc ";}
};
class D{
public:
    C c;
    D(){cout<<"D0 ";}
};
main(){
    D x; cout<<endl; // C0 D0
    D y(x);cout<<endl; // Cc -> viene richiamato il costruttore di copia standard di D, il quale richiama il costruttore di copia di ogni campo dato di D
}
*/
/*
// es pagina 56
class C{
public:
    C(){cout<<"C0 ";}
    C(const C&){cout<<"Cc ";}
};
class D{
public:
    C c;
    D(){cout<<"D0 ";}
    D(const D&){cout<<"Dc ";}
};
main(){
    D x; cout<<endl; // C0 D0
    D y(x);cout<<endl; // C0 Dc
}
*/
// es pagina 55
/*
class D{
private:
    int z;
public:
    D(int x=0):z(x){cout<<"D01 ";}
    D(const D& a):z(a.z){cout<<"Dc ";}
};
class C{
private:
    D d;
public:
    C():d(D(5)){cout<<"C0 ";}
    C(int a):d(5){cout<<"C1 ";}
    C(const C& c):d(c.d){cout<<"Cc ";}
};
main(){
    C c1;cout<<" UNO "<<endl; // D01 Dc C0
    C c2(3);cout<<" DUE "<<endl; // D01 C1
    C c3(c2);cout<<" TRE "<<endl; // Dc Cc
}
*/
/*
// es pagina 55 -> definire un costruttore legale per la classe C
class E{
private:
    int x;
public:
    E(int z=0):x(z){}
};
class C{
private:
    int z;
    E x;
    const E e;
    E& r;
    int* const p;
public: // definire un costruttore legale per la classe C
    C();
};
C::C():z(0),x(0),e(),r(x),p(&z){} // alternative: avrei potuto omettere "x" ed "e". notare che e() (senza parametro) funziona
main(){}
*/
/*
// es pagina 53
class D{
public:
    D(){cout<<"D0 ";}
    D(int a){cout<<"D1 ";}
};
class E{
private:
    D d;
public:
    E(): d(3){cout<<"E0 ";}
    E(double a,int b){cout<<"E2 ";}
    E(const E& a):d(a.d){cout<<"Ec ";}
};
class C{
private:
    int z;
    E e;
    D d;
    E* p;
public:
    C():p(0),e(),z(4){cout<<"C0 ";}
    C(int a,E b): e(3.7,2),p(&b),z(1),d(3){cout<<"C1 ";}
    C(char a,int b):e(),d(2),p(&e){cout<<"C2 ";}
};
main(){
    E e; cout<<endl; // D1 E0
    C c; cout<<endl; // D1 E0 D0 C0
    C c1(1,e); cout<<endl; // Ec D0 E2 D1 C1
    C c2('b',2); cout<<endl; // D1 E0 D1 C2
}
*/
/*
// es pagina 48
class C{
private:
    int x;
public:
    C(){cout<<"C0 "; x=0;}
    C(int k){cout<<"C1 ";x=k;}
};
class D{
private:
    C c;
public:
    D(){cout<<"D0 ";c=C(3);}
};
class E{
private:
    char c;
    C c1;
public:
    D d;
    C c2;
};

main(){
  D y;cout<<endl; // C0 D0 C1
  E x; cout<<endl; // C0 C0 D0 C1 C0
  E* p=&x;
  D& a=y;cout<<endl;
}
*/
/*
// es pagina 39
class C{
public:
    C(){}
    C(const C& r){cout<<"*";} // costruttore di copia ridefinito
};
C f(C a){
    C b(a); C c=b; return c;
}
int main(){
    C x; C y=f(f(x)); // ********* (sono 9 star)
}
*/
/*
// es pagina 36
class Puntatore{
public:
    int* punt;
};
int main(){
    Puntatore x,y;
    x.punt=new int(8);
    y=x;
    cout<<"*(y.punt)="<<*(y.punt)<<endl; // 8
    *(y.punt)=3;
    cout<<"*(x.punt)="<<*(x.punt)<<endl; // 3
}
*/
// es pagina 31
/*
class C{
    int dato; // privato
public:
    C(int);
    static int cont;
};
int C::cont=0;
C::C(int n){cont++; dato=n;}
int main(){
    C c1(1),c2(3);
    cout<<C::cont; // stampa 2
}
*/
