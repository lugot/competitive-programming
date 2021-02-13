import java.util.Scanner;

public class UnbearableZoo
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int listIndex=1; 
        while (in.hasNextLine())
        {
            int n=Integer.parseInt(in.nextLine());
            
            int animalIndex=0;
            String[][] animalList = new String[n][2];
            
            for (int i=0; i<n; i++)
            {
                String line=in.nextLine();
                Scanner lineScan = new Scanner(line);
                
                String animal="";
                while (lineScan.hasNext()) //becco nome dell'animale
                    animal=lineScan.next().toLowerCase();
                
                boolean flag=false;
                for (int k=0; k<animalIndex; k++) //ricerca ricorreze
                {   
                    if (animalList[k][0].equals(animal))
                    {
                        animalList[k][1]=(Integer.parseInt(animalList[k][1])+1)+"";
                        flag=true;
                        break;
                    }
                }
                if (flag==false) //new entry
                {
                    animalList[animalIndex][0]=animal;
                    animalList[animalIndex++][1]=1+"";
                }
                
                
            }
            
            //sorto alfanumericamente la matrice animalList per la prima riga coi nomi degli animalIndex
            int u,v;
            for (v=0; v<animalIndex-1; v++)
            {
                int uMin=v;
                for (u=v+1; u<animalIndex; u++)
                {
                    if (animalList[u][0].compareTo(animalList[uMin][0])<0)
                        uMin=u;
                }
                if (uMin!=v)
                {   
                    String temp0=animalList[v][0], temp1=animalList[v][1];
                    animalList[v][0]=animalList[uMin][0]; animalList[v][1]=animalList[uMin][1];
                    animalList[uMin][0]=temp0; animalList[uMin][1]=temp1;
                }
            }
            
            if (n!=0) System.out.println("List " + listIndex++ + ":");
            for (int i=0; i<animalIndex; i++)
            {
                System.out.println(animalList[i][0]+" | "+animalList[i][1]);
            }
        }
    }
}
