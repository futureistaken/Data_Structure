/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sortingalgorithms;

/**
 *
 * @author babakfarahmand
 */
public class LinkedList {

    private Node head;

    public LinkedList() {
        head = null;
    }

// First node
    //initializing - Constructor LinkedList class
    private class Node {

        private int data; // Contain the Data of the obj
        private Node next; //Contain the address of the next obj
        private Node prev; // Contain the address of the previous obj

        //initializing - Constructor Node class
        private Node() {
            next = null;
            prev = null;

        }
    }

    public void add(int data) {
        Node node = new Node();
        node.data = data;
        node.next = null;
        node.prev = null;
        if (head == null) {
            head = node;
        } else {
            Node n = head; // temporary node - for travel through the list
            while (n.next != null) { // will loop till get to the end of the list
                n = n.next;
            }
            n.next = node; // assign the last node(n) to the new node
            node.prev = n; 
        }
    }

    public void deleteByData(int data) {
        Node n = head;
        if (n != null) {
            while (n.next != null) {
                head = n.data == data ? n.next : head; // if we are deleting the head
                if (n.next.data == data) {
                    n.next = n.next.next;
                } else {
                    n = n.next;
                }
            }
            // if we are deleting the last element
            // that last elemet is head 
            if (n.data == data) {
                head = null;
            }
        } else {
            System.out.print("List is Empty Delete();");
        }
    }

    public void deleteByIndex(int index) {
        Node n = head;
        int i = 0;
        if (n != null) {
            while (n.next != null) {
                if (i == index) {
                    head=n.next;
                    i++;
                    break;
                }
                if (i+1 == index) {
                    n.next = n.next.next;
                    break;
                }
                if (n.next == null) {
                    n.next = null;
                break;
                }
                n=n.next;
                i++;
            }
            // if we are deleting the last element
            // that last elemet is head 
            if (i == index) {
                head = null;
            }
        } else {
            System.out.print("List is Empty Delete();");
        }

    }

    public void printAllNodes() {
        Node n = head;
        if (n == null) {
            System.out.print("List is Empty ");
        } else {
            while (n != null) {
                System.out.printf("%d ", n.data);
                n = n.next;
            }
        }
        System.out.print("\n");
    }
}
