 class Solution{
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> result1 = new ArrayList<>();
        List<Integer> result2 = new ArrayList<>();
        for(int i=0;i<matrix.length;i++){
            int minimum =matrix[i][0];
            for(int j=1;j<matrix[0].length;j++){
                if(matrix[i][j]<minimum){
                    minimum = matrix[i][j];
                }
            }
            result1.add(minimum);
        }
        
        for(int j=0;j<matrix[0].length;j++){
            int maximum =matrix[0][j];
            for(int i=1;i<matrix.length;i++){
              if(matrix[i][j]>maximum){
                maximum = matrix[i][j];
              } 
            }
        result2.add(maximum); 
        }
        result1.retainAll(result2);
        System.gc();
        return result1;
    }
 }

