class BinarySearch{
    public static void main(String[] a){
	System.out.println(new BS().Start(20));
    }
}

class BS{
	int[] number ;
    int size ;

	public int Start(int sz){
		int aux01 ;
		int aux02 ;
		aux01 = this.Init(sz);
		aux02 = this.Print();
		if (this.Search(8)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(19)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(20)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(21)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(37)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(38)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(39)) System.out.println(1) ;
		else System.out.println(0) ;
		if (this.Search(50)) System.out.println(1) ;
		else System.out.println(0) ;

		return 999 ;
    }

}
