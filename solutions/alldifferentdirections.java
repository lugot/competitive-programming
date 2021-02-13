import java.util.Scanner;

public class alldifferentdirections
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        int n=Integer.parseInt(in.nextLine());
        do
        {
            double[][] positions = new double[n][2];
            
            for (int k=0; k<n; k++)
            {
                String[] indications = in.nextLine().split(" "); //ristrutturato, così è brutto come la fame
                
                double x=Double.parseDouble(indications[0]);
                double y=Double.parseDouble(indications[1]);
                
                double alpha=0;
                double length=0;
                
                for (int j=2; j<indications.length;)
                {
                    String action=indications[j++];
                    if (action.equals("start") || action.equals("turn"))
                        alpha+=Double.parseDouble(indications[j++]);
                    else
                        length=Double.parseDouble(indications[j++]);
                    
                    
                    //System.out.println(action+" "+alpha+" "+length);
                    
                    if (action.equals("walk"))
                    {
                        x+=length*Math.cos(Math.toRadians(alpha));
                        y+=length*Math.sin(Math.toRadians(alpha));
                    }
            
                }
                positions[k][0]=x;
                positions[k][1]=y;
                //System.out.println(positions[k][0]+" "+positions[k][1]);
            }
            
            
            double avgx=0;
            double avgy=0;
            for (int i=0; i<n; i++)
            {
                avgx+=positions[i][0];
                avgy+=positions[i][1];
            }
            avgx/=n;
            avgy/=n;
            
            double worst=0;
            for (int i=0; i<n; i++)
            {
                double distance=Math.sqrt(
                    (avgx-positions[i][0])*(avgx-positions[i][0]) +
                    (avgy-positions[i][1])*(avgy-positions[i][1]) );
                
                if (i==0 || distance>worst)
                    worst=distance;
            }
            
            System.out.println(avgx+" "+avgy+" "+worst);
            
            n=Integer.parseInt(in.nextLine());
        }while(n!=0);
    }
}
