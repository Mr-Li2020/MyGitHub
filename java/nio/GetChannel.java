package com.google.javase.nio;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

public class GetChannel {
	private static int BESIZE = 1024;
	
	private static void ChannelWrite() {
		try {
			FileOutputStream fos = new FileOutputStream("E:\\javaseio\\my\\mine\\test.txt");  //OutputStream��û��ʵ��FileChannel
			FileChannel fc = fos.getChannel();
			fc.write(ByteBuffer.wrap("The day".getBytes()));
			fc.close();
			fos.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void RandomWrite() {
		try {
			RandomAccessFile raf = new RandomAccessFile("E:\\javaseio\\my\\mine\\test.txt","rw");
			FileChannel fc = raf.getChannel();
			fc = raf.getChannel();
			fc.position(fc.size());   //׷�ӵ�д 
			fc.write(ByteBuffer.wrap(" is very happy".getBytes()));
			fc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	private static void ChannelRead() {
		//�����д
		try {
			FileInputStream fis = new FileInputStream("E:\\javaseio\\my\\mine\\test.txt");
			FileChannel fc = fis.getChannel();
			ByteBuffer buf = ByteBuffer.allocate(BESIZE);
			fc.read(buf);   //���ļ����ݶ��뻺����
			buf.flip();   //��position = limit
			while(buf.hasRemaining()) {
				System.out.print((char)buf.get());
			}
			fis.close();
			fc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		ChannelWrite();
		RandomWrite();
		ChannelRead();
	}
}		
		

		



