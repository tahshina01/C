class xm {
    static int a;
    static int b;
    static{
        System.out.println("a: "+ a+",b: "+ b);
    }
    {
        b++;
        System.out.println("b in block: "+ b);
    }
    public xm(){
        System.out.println("constructor");
    }
    public static void main(String[] args){
        System.out.println("some text.");
        xm ob =new xm();
        xm ob2= new xm();
    }

}
