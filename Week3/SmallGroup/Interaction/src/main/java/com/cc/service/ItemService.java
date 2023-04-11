package com.cc.service;


import com.cc.pojo.Item;

import java.util.List;

public interface ItemService {

    /**
     * 查询所有
     * @return
     */
    List<Item> selectAll();

    /**
     * 添加数据
     * @param item
     */
    void add(Item item);
}
