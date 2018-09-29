//package assignmentOne;

import java.util.Scanner;

public class RockPaperScissors {

    public static void main(String[] args) 
    {
        // TODO Auto-generated method stub
        
        Scanner scanner = new Scanner (System.in); 
        String str[] = {"가위", "바위", "보"};
        int result[] = {"","",""};    
        String userString = "";
        boolean go = true;
        System.out.print("컴퓨터와 가위 바위 보 게임을 합니다.");
        System.out.print("가위 바위 보!");
        while((userString = scanner.next()) != "종료")
        {
            int n = (int)(Math.random()*3);
            if(userString == str[0])
            {
                result[0] = "비겼습니다";
                result[1] = "졌습니다";
                result[2] = "이겼습니다";
            }
            else if(userString == str[1])
            {
                result[0] = "이겼습니다";
                result[1] = "비겼습니다";
                result[2] = "졌습니다";
            }
            else{
                result[0] = "졌습니다";
                result[1] = "이겼습니다";
                result[2] = "비겼습니다";
            }
            System.out.print("사용자 = " + userString + ", 컴퓨터 ="+ str[n] + " " + result[n]);

            System.out.print("컴퓨터와 가위 바위 보 게임을 합니다.");
            System.out.print("가위 바위 보!");
            
        }
      
      
   }
   
}