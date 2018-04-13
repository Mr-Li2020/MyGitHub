package com.google.javase.nio;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.zip.GZIPOutputStream;
/**
 * ͼƬѹ��������
 * @author liningbo
 * @date:2018��3��25������4:20:02
 * @version 1.0
 */

public class GzipUtils {
	public static void gzip(byte[] data) {
		try {
			//ѹ����Ҫ��ByteArrayOutputStreamһ��ʹ��
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			GZIPOutputStream gos = new GZIPOutputStream(baos);
			gos.write(data);
			gos.flush();
			//ѹ��֮���ļ���С
			byte[] bytes = baos.toByteArray();
			baos.close();
			gos.close();
			System.out.println("ѹ�����ļ���С:"+bytes.length);
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	public static void main(String[] args) {
		File file = new File("E:\\javaseio\\my\\������.jpg");
		try {
			InputStream fis = new FileInputStream(file);
			byte[] bytes = new byte[fis.available()];
			fis.read(bytes);    //�����ڴ�
			fis.close();
			System.out.println("ѹ��ǰ���ļ���С:"+bytes.length);
			gzip(bytes);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
