package com.google.javase.nio;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileChannel.MapMode;

public class CopyFileDeom {

	private static void RandomAccessFileCopy() {
		try {
			RandomAccessFile in = new RandomAccessFile("E:\\javaseio\\my\\������.jpg", "r");
			RandomAccessFile out = new RandomAccessFile("E:\\javaseio\\my\\me\\Like.jpg", "rw");
			FileChannel fcin = in.getChannel();
			FileChannel fcout = out.getChannel();

			long size = fcin.size(); // ���������ֽڴ�С
			// �������Ļ�����
			MappedByteBuffer inbuf = fcin.map(MapMode.READ_ONLY, 0, size);
			// ������Ļ�����
			MappedByteBuffer outbuf = fcout.map(MapMode.READ_WRITE, 0, size);
			for (int i = 0; i < size; i++) {
				outbuf.put(inbuf.get());
			}
			System.out.println("Copy Success.");
			// �ر�ͨ��ʱ��д�����ݿ�
			in.close();
			out.close();
			fcin.close();
			fcout.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * ͨ���ļ�ͨ��ʵ���ļ�����
	 * 
	 * @throws Exception
	 */
	private static void CopyFile() throws Exception {
		// ����һ���ļ�����ͨ��
		FileChannel fcin = new FileInputStream("E:\\javaseio\\my\\������.jpg").getChannel();
		// ����һ���ļ����ͨ��
		FileChannel fcout = new FileOutputStream("E:\\javaseio\\my\\me\\������.jpg").getChannel();
		ByteBuffer buf = ByteBuffer.allocate(1024);
		while (fcin.read(buf) != -1) {
			buf.flip();
			fcout.write(buf);
			buf.clear();
		}
		System.out.println("Copy Success.");
		fcout.close();
		fcin.close();
	}

	public static void main(String[] args) {
		try {
			// CopyFile();
			RandomAccessFileCopy();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
