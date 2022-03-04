class Example {
    public static void fun(int x) {
        x = 1;
    }
    public static void main(String[] args) {
        int s = 0;
        fun(s);
        System.out.println(s);
    }
}