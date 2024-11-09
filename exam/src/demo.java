class Case {
    int a,b,c;
    Case(int a, int b, int c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
}
class B extends Case {
    int a,b,c,d,e;


    B(int a, int b, int c,int d,int e) {
        super(a, b, c);
        this.a=a;
        this.b=b;
        this.c=c;
        this.d=d;
        this.e=e;
    }
}
class A extends B{
    int a,b,c,d,e,f;
    A(int a,int b,int c,int d,int e,int f){
        super(a,b,c,d,e);
        this.a=a;
        this.b=b;
        this.c=c;
        this.d=d;
        this.e=e;
        this.f=f;
    }
}
public class demo {
    public static void main(String[] args) {
        B a = new A(3, 2, 5, 6, 4, 3);
        B b = new B(2, 4, 1, 4, 5);
        C c = new C(4, 2, 4);
        System.out.println(a.a+" " +a.b+" "+ a.c+" "+ a.d+" "+a.e);
        System.out.println(a.a+ a.b+ a.c+a.d+a.e);

    }
}
