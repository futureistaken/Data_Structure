/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sortingalgorithms;

import java.io.*;
import java.util.*;
import static sortingalgorithms.Hackerrank.*;

/**
 *
 * @author babakfarahmand
 * @param <T>
 */
public class SortingAlgorithms<T> {

    // Selection Sort
    // WorstCase{O(n^2)} , BestCase{O(n^2)}
    public static void SelectionSort(int[] a) {
        int newMin;
        int temp;
        int index = 0;
        for (int i = 0; i < a.length; i++) { // define the newMin
            newMin = a[i];
            for (int j = i + 1; j < a.length; j++) { // finds the newMin
                if (newMin > a[j]) {
                    index = j;
                    newMin = a[j];
                }
            }
            if (i + 1 == a.length) { // check to see if the last element had been checked
                break;
            }
            temp = a[index]; // swap the newMin value with the oldMin value
            a[index] = a[i];
            a[i] = temp;
        }
    }

    // Insertion Sort - O(N^2)
    // WorstCase{O(n^2)} , BestCase{O(n)}
    public static void InsertionSort(int[] a) {
        int temp;
        int H; // loop holder
        for (int i = 0; i < a.length; i++) {
            H = i;
            // check if all the values are checked,
            // Break to avoid Error during the H+1 check
            if (H + 1 == a.length) {
                break;
            }
            // checke the value with all the previous values
            while (a[H] > a[H + 1]) {
                temp = a[H + 1];
                a[H + 1] = a[H];
                a[H] = temp;
                if (0 < H) {
                    H--;
                }
            }
        }
    }

    // Bubble Sort
    //  WorstCase{O(n^2)} , BestCase{O(n)}
    public static void BubbleSort(int[] a) {
        int temp;
        for (int i = (a.length) - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    // Quick Sort
    // Partiton / Pivot Currect Position
//    public static int partition(int[] a, int low, int high) {
//        int pivot = low;
//        int temp;
//        int i = 0;
//        int j = high;
//        if (high == 3) {
//            if (a[low + 1] >  a[high - 1]) {
//                temp = a[j - 1];
//                a[j - 1] = a[pivot + 1];
//                a[pivot + 1] = temp;
//            }
//        }
//
//        for (int k = 0; k < high; k++) {
//            i++;
//            if (i > j) {
//                break;
//            }
//            if (a[i] > a[pivot]) {
//                for (int l = j; l > low; l--) {
//
//                    if (a[j] < a[pivot]) {
//                        temp = a[i];
//                        a[i] = a[j];
//                        a[j] = temp;
//                    }
//                    j--;
//                    break;
//                }
//            }
//        }
//
//        temp = a[j];
//        a[j] = a[pivot];
//        a[pivot] = temp;
//        return j;
//    }
//
//    public static void QuickSort(int[] a, int low, int high) {
//        //PrintArry(a);
//        if (low < high) {
//            int j = partition(a, low, high);
//            QuickSort(a, low, j);
//            QuickSort(a, j + 1, high);
//        }
//    }
    public static void MergeSort() {
    }

    public static void Merg() {
    }

    public static void HeapSort() {
    }

    public static void PrintArry(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {
        
        
        int[] a={5,3,2,1,4,2};
        PrintArry(a);
        System.out.println();
        InsertionSort(a);
        PrintArry(a);

//        int[][] arr = new int[3][3];
//        arr[0][0] = 11 ;
//        arr[0][1] = 2 ;
//        arr[0][2] = 4 ;
//        arr[1][0] = 4 ;
//        arr[1][1] = 5 ;
//        arr[1][2] = 6 ;
//        arr[2][0] = 10 ;
//        arr[2][1] = 8 ;
//        arr[2][2] = -12 ;
//        System.out.print((diagonalDifference(arr)));

        
        

// initializing an ArrayList
//        List<Integer> a = new ArrayList<Integer>();
//        List<Integer> b = new ArrayList<Integer>();
//        a.add(17);
//        a.add(28);
//        a.add(30);
//        
//        b.add(99);
//        b.add(16);
//        b.add(8);
//        List<Integer> result = compareTriplets(a, b);
//        Iterator<Integer> values = result.iterator();
//        while(values.hasNext()){
//        System.out.printf("%s ", values.next());
//        }

//        BufferedReader input = new BufferedReader(new FileReader("input"));
//        String str;
//        //creating an arraylist - to add an unlimited line to our array
//        List<String> list = new ArrayList<String>();
//        while ((str = input.readLine()) != null) {
//            list.add(str);
//        }
//        //convert back to array for the ease
//        String[] strArr = list.toArray(new String[0]);
//        // print the array
//        for (String data : strArr) {
//            System.out.printf("%s", data + "\n");
//        }
//        input.close();
    }
}

//In Xanadu did Kubla Khan
//A stately pleasure-dome decree:
//Where Alph, the sacred river, ran
//Through caverns measureless to man
//Down to a sunless sea.
