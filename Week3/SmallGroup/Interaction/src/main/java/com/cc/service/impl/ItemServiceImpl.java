package com.cc.service.impl;

import com.cc.mapper.ItemMapper;
import com.cc.pojo.Item;
import com.cc.service.ItemService;
import com.cc.util.SqlSessionFactoryUtils;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;


public class ItemServiceImpl implements ItemService {
    //1. 创建SqlSessionFactory 工厂对象
    SqlSessionFactory factory = SqlSessionFactoryUtils.getSqlSessionFactory();


    @Override
    public List<Item> selectAll() {
        //2. 获取SqlSession对象
        SqlSession sqlSession = factory.openSession();
        //3. 获取BrandMapper
        ItemMapper mapper = sqlSession.getMapper(ItemMapper.class);

        //4. 调用方法
        List<Item> items = mapper.selectAll();

        //5. 释放资源
        sqlSession.close();

        return items;
    }

    @Override
    public void add(Item item) {
        //2. 获取SqlSession对象
        SqlSession sqlSession = factory.openSession();
        //3. 获取ItemMapper
        ItemMapper mapper = sqlSession.getMapper(ItemMapper.class);

        //4. 调用方法
        mapper.add(item);
        sqlSession.commit();//提交事务

        //5. 释放资源
        sqlSession.close();
    }
}
