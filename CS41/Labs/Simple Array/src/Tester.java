/**
 * @author Mike Zrimsek
 * @version 01.20.2014
 */

import java.util.Scanner;

public class Tester {
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int[] nums = new int[5];
		for(int i = 0; i < nums.length; i++)
		{
			System.out.print("Enter number: ");
			nums[i] = sc.nextInt();
		}
		
		System.out.print("[ ");
		for(int x : nums)
			System.out.print(x + " ");
		System.out.print("]");
	}
}
