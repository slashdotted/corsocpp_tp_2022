class Example2 {
    public static void fun(java.lang.String x) {
        x = "hello world";
    }
    public static void main(java.lang.String[] args) {
        java.lang.String s = "hello moon";
        fun(s);
        System.out.println(s);
    }
}