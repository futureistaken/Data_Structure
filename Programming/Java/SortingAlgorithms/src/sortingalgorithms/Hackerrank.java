package sortingalgorithms;

import static java.lang.Math.*;
import java.util.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author babakfarahmand
 */
public class Hackerrank {

    static int SocksMatch(int n, int[] ar) {
        int[] a = new int[n];
        System.arraycopy(ar, 0, a, 0, n);
        int SocksC = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] == -1) {

                if (i == n - 1) {
                    break;
                }
                i++;
            }
            if (i == n - 1) {
                break;
            }
            for (int j = i + 1; j < n; j++) {
                while (a[j] == -1) {
                    if (j == n - 1) {
                        break;
                    }
                    j++;
                }
                if (a[i] == a[j]) {
                    SocksC++;
                    a[i] = -1;
                    a[j] = -1;
                    break;
                }

            }
        }
        return SocksC;
    }

    static int jumpingOnClouds(int[] c) {
        int jump = 0;
        for (int i = 0; i < c.length - 1;) {
            if (c[i] != 0 && c[i] != 1) {
                i++;
            }

            if (c[i] == 0) {
                i++;
                jump++;
                //break;
                if (i == c.length - 1) {
                    break;
                }

            }
            if (c[i] == 1) {
                i++;
                //break;
                if (i == c.length - 1) {
                    break;
                }
            }
            if (c[i + 2] == 0) {
                i = i + 2;
                jump++;
                if (i >= c.length) {
                    break;
                }

            }
        }

        return jump;
    }

    static int simpleArraySum(int[] ar) {
        int sum = 0;
        for (int i = 0; i < ar.length; i++) {
            sum += ar[i];
        }
        return sum;
    }

    static List<Integer> compareTriplets(List<Integer> a, List<Integer> b) {
        // creating a list to store the result
        List<Integer> result = new ArrayList<Integer>();
        result.add(0);
        result.add(0);

        // score holder 
        int aScore = 0;
        int bScore = 0;

        // walkthrough each element and compare
        for (int i = 0; i < a.size(); i++) {
            for (int j = i; j < b.size(); j++) {
                if (a.get(i) > b.get(j)) {
                    ++aScore;
                    result.set(0, aScore);
                    break;
                } else if (a.get(i) < b.get(j)) {
                    ++bScore;
                    result.set(1, bScore);
                    break;
                } else {
                    break;
                }
            }
        }
        return result;

    }

    static long aVeryBigSum(long[] ar) {
        long result = 0;
        for (int i = 0; i < ar.length; i++) {
            result += ar[i];
        }

        return result;

    }

    static int diagonalDifference(int[][] arr) {
        int col_size = arr[0].length; // size of the row
        int a = 0; // holds the sum of the first diagnol
        int b = 0; // holds the sum of the second diagnol
        int j = 0; // holds the value of the row
        int i = 0;
        for (; i < col_size; i++) {
            j = i;
            a += arr[i][j];
        }
        i = 0;
        for (; i < col_size; i++) {
            b += arr[i][j];
            j--;
        }
        if ((a - b) < 0) {
            return (a - b) * -1;
        } else {
            return (a - b);
        }
    }


    /*
     * Complete the 'countSentences' function below.
     *
     * The function is expected to return a LONG_INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. STRING_ARRAY wordSet
     *  2. STRING_ARRAY sentences
     */
    public static List<Long> countSentences(List<String> wordSet, List<String> sentences) {
        int CharCounter = 0;
        int word_lenght_first_String = 0;
        int word_lenght_Second_String = 0;
        for (int i = 0; i < wordSet.size() - 1; i++) {
            for (int j = i + 1; j < wordSet.size(); j++) {
                word_lenght_first_String = wordSet.get(i).length();
                word_lenght_Second_String = wordSet.get(j).length();
                if (word_lenght_first_String == word_lenght_Second_String) {
                    
                        if (true) {
                            
                        }
                    }
                }
            }
        

        return null;
        // Write your code here

    }

}
