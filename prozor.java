import java.util.Scanner;

public class prozor
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int R=in.nextInt();
        int S=in.nextInt();
        int K=in.nextInt();
        in.nextLine();
        
        int[][] win=new int[R][S];
        for (int i=0; i<R; i++)
        {
            String line=in.nextLine();
            for (int j=0; j<S; j++)
                win[i][j]=(line.charAt(j)=='*' ? 1 : 0);
        }
        
        int kills=0;
        int maxKills=0;
        int x=0,y=0;
        for (int i=1; i<=R-K+1; i++){
            for (int j=1; j<=S-K+1; j++){
                kills=0;                
            
                for (int k=0; k<K-2; k++){
                    for (int z=0; z<K-2; z++){
                        
                        kills+=win[i+k][j+z];
                    }
                }
                
                if (kills>maxKills)
                {
                    maxKills=kills;
                    x=i; y=j;
                }
            }
        }
        x--; y--; //segno posizione angolo
        
        char[][] out = new char[R][S];
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<S; j++)
            {
                if (( i==x || i==x+K-1 ) && j==y)
                {
                    out[i][j]='+';
                    int k=1;
                    for (; k<=K-2;k++) out[i][j+k]='-';
                    out[i][j+k]='+';
                    j+=K-1;
                }
                else if ( i>x && i<x+K-1 && (j==y || j==y+K-1 ))
                    out[i][j]='|';
                else
                {
                    if (win[i][j]==0)
                        out[i][j]='.';
                    else
                        out[i][j]='*';
                }
            }
        }
        
        //OUT
        System.out.println(maxKills);
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<S; j++)
                System.out.print(out[i][j]);
            System.out.println();
        }        
    }
}
