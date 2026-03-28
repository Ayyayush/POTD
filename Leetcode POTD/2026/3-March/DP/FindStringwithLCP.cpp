import java.util.*;

public class Solution {

    public static int MaxTasks(int N, int C, List<List<Integer>> Tasks) {
        int maxTasks = 0;

        for (int mask = 0; mask < (1 << N); mask++) {
            if (Integer.bitCount(mask) <= maxTasks) continue;

            List<int[]> selected = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                if ((mask & (1 << i)) != 0) {
                    selected.add(new int[]{Tasks.get(i).get(0), Tasks.get(i).get(1)});
                }
            }

            Collections.sort(selected, (a, b) -> a[0] - b[0]);

            int capital = C;
            boolean valid = true;

            for (int i = 0; i < selected.size(); i++) {
                int deadline = selected.get(i)[0];
                int profit = selected.get(i)[1];

                int time = i + 1;

                if (deadline < time) {
                    valid = false;
                    break;
                }

                capital += profit;

                if (capital < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                maxTasks = Math.max(maxTasks, selected.size());
            }
        }

        return maxTasks;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int N = Integer.parseInt(scan.nextLine().trim());
        int C = Integer.parseInt(scan.nextLine().trim());

        List<List<Integer>> Tasks = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String[] parts = scan.nextLine().trim().split(" ");
            int d = Integer.parseInt(parts[0]);
            int p = Integer.parseInt(parts[1]);
            Tasks.add(Arrays.asList(d, p));
        }

        int result = MaxTasks(N, C, Tasks);
        System.out.println(result);
    }
}