import java.util.Scanner;
import java.util.ArrayList;
import java.util.TreeMap;

public class calculatingdartscores
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int score = sc.nextInt();
        TreeMap<Integer,Node> tm = new TreeMap<Integer,Node>();
        EasyQueue<Node> eq = new EasyQueue<Node>();
        Node root = new Node(score, new int[]{0,0}, 0);
        tm.put(new Integer(root.getValue()), root);
        eq.enqueue(root);
        ArrayList<Node> solution = new ArrayList<Node>();
        DANCE:
        while (true) {
            try {
                Node n = eq.dequeue();
                int v = n.getValue();
                int attempt = n.getAttempt()+1;
                for (int i = 1; i <= 20; i++) {
                    for (int j = 1; j <= 3; j++) {
                        int nuv = v-(i*j);
                        if (nuv == 0) {
                            n = new Node(nuv, new int[]{i,j}, attempt);
                            while (attempt > 0) {
                                solution.add(n);
                                int par = n.getValue()+(n.getPath()[0]*n.getPath()[1]);
                                n = tm.get(new Integer(par));
                                attempt = n.getAttempt();
                            }
                            break DANCE;
                        }
                        else if ((nuv > 0) && (attempt < 3)) {
                            if (tm.get(new Integer(nuv)) == null) {
                                Node nun = new Node(nuv, new int[]{i,j}, attempt);
                                tm.put(new Integer(nuv), nun);
                                eq.enqueue(nun);
                            }
                        }
                    }
                }
            }
            catch (EmptyQueueException e) {
                break DANCE;
            }
        }
        if (solution.size() == 0)
            System.out.println("impossible");
        else {
            for (int i = 0; i < solution.size(); i++) {
                Node n = solution.get(i);
                int[] p = n.getPath();
                switch (p[1]) {
                  case 1:
                    System.out.print("single ");
                    break;
                  case 2:
                    System.out.print("double ");
                    break;
                  case 3:
                    System.out.print("triple ");
                    break;
                }
                System.out.println(p[0]);
            }
        }
    }


    private static class Node {

        private int value;
        private int[] path;
        private int attempt;

        public Node(int v, int[] p, int a) {
            value = v;
            path = new int[2];
            System.arraycopy(p, 0, path, 0, 2);
            attempt = a;
        }

        public int getValue() {
            return value;
        }
        public int[] getPath() {
            return path;
        }
        public int getAttempt() {
            return attempt;
        }

    }

}
