import java.util.Scanner;

public class QuickSort {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String str = sc.nextLine();
		String ans = "";
		
		int spaces = 0, len = str.length()-1;
		
		while(len>=0) {
			while(len >= 0 && str.charAt(len) == ' ') {
				len--;
				spaces++;
			}
			int j = len;
			
			if(len<0) { break;}
			
			while(len >= 0 && str.charAt(len) != ' ') {
				len--;
			}
			
			if(ans.isEmpty()) {
				ans = ans.concat(str.substring(len+1,j+1));
			
			}else {
				while(spaces >= 0) {
					if(spaces == 0) {
						ans = ans.concat(str.substring(len+1,j+1));
						break;
					}
					ans = ans.concat(" ");
					spaces--;
				}
				spaces = 0;
			}
		}
		
		str = ans.toString();
		System.out.println(str);
	}

}
