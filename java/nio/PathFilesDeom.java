package com.google.javase.nio;

import java.io.File;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.nio.file.StandardOpenOption;



public class PathFilesDeom {

	public static void main(String[] args) {
		//Path�ӿ�
		File file = new File("E:\\javaseio\\my\\������.jpg");
		Path p1 = Paths.get("E:\\javaseio\\my", "������.jpg");
		System.out.println(p1);
		Path p2 = file.toPath();
		System.out.println(p2);
		Path p3 = FileSystems.getDefault().getPath("E:\\javaseio\\my", "������.jpg");
		System.out.println(p3);
		
		//Files������
		Path p4 = Paths.get("E:\\javaseio\\my\\mine\\your.txt");
		//д���ļ�
//		String info = "Ŭ��ѧϰ���ܶ���ֹ";
//		try {
//			Files.write(p4, info.getBytes("gb2312"), StandardOpenOption.APPEND);
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
		//��ȡ�ļ�
		try {
			byte[] bytes = Files.readAllBytes(p4);
			System.out.println(new String(bytes));
		} catch (IOException e) {
			e.printStackTrace();
		}
		Path p5 = Paths.get("E:\\ͼƬ", "Like.jpg");
		//�����ļ�
//		try {
//			Files.copy(Paths.get("E:\\javaseio\\my\\me\\HEAT.jpg"), Paths.get("E:\\ͼƬ\\Like.jpg"), StandardCopyOption.COPY_ATTRIBUTES);
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//		//�ƶ��ļ�
//		try {
//			Files.move(p5, Paths.get("E:\\javaseio\\my\\me\\HEAT.jpg"), StandardCopyOption.ATOMIC_MOVE);
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//		//ɾ���ļ�
//		try {
//			Files.delete(Paths.get("E:\\javaseio\\my\\me\\HEAT.jpg"));
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
		//������Ŀ¼
//		try {
//			Files.createDirectory(Paths.get("E:\\javaseio\\your"));
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
		//����һ��һ����ļ�
		try {
			Files.createDirectories(Paths.get("E:\\javaseio\\Her\\she\\hers"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
