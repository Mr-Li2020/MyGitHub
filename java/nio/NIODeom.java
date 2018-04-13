package com.google.javase.nio;

import java.nio.ByteBuffer;

/**
 * NIO�Կ�ķ�ʽ�������ݣ����е����ݶ����ڻ����������
 * @author liningbo
 * @date:2018��3��26������3:52:32
 * @version 1.0
 */
public class NIODeom {

	public static void main(String[] args) {
		ByteBuffer buf = ByteBuffer.allocate(8);
		System.out.println("position:"+buf.position());
		System.out.println("limit:"+buf.limit());
		System.out.println("capacity:"+buf.capacity());
		buf.put((byte) 10);
		buf.put((byte) 20);
		buf.put((byte) 30);
		buf.put((byte) 40);
		System.out.println("----------------");
		System.out.println("position:"+buf.position());
		System.out.println("limit:"+buf.limit());
		System.out.println("capacity:"+buf.capacity());
		//��������ת��ȡ��ǰ�ֽ�
		buf.flip();
		System.out.println("----------------");
		System.out.println("position:"+buf.position());
		System.out.println("limit:"+buf.limit());
		System.out.println("capacity:"+buf.capacity());
//		while(buf.hasRemaining()) {
//			System.out.println(buf.get());
//		}
		if(buf.hasRemaining()) {
			for(int i=buf.position();i<buf.remaining();i++) {
				byte b = buf.get(i);
				System.out.println(b);
			}
		}
		System.out.println("----------------");
		System.out.println("position:"+buf.position());
		System.out.println("limit:"+buf.limit());
		System.out.println("capacity:"+buf.capacity());
	}

}
