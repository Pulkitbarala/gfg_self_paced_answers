class Solution {
    public ArrayList<Integer> quadraticRoots(int a, int b, int c) {
        // code here
        ArrayList<Integer> d = new ArrayList<Integer>();
        double det = ( (b*b) - (4.0 * a * c) );
        if( det < 0 ) { // check if no roots exist
            d.add(-1);
            return d;
        }
        det = Math.sqrt(det);
        double detPlus = Math.floor((-b+det)/(2.0*a));
        double detMinus = Math.floor((-b-det)/(2.0*a));
        if(detPlus < detMinus) {
            d.add((int)detMinus);
            d.add((int)detPlus);
        } else {
            d.add((int)detPlus);
            d.add((int)detMinus);
        }
        return d;
    }
}