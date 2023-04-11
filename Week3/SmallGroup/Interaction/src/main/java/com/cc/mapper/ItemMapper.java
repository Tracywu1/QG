package com.cc.mapper;

import com.cc.pojo.Item;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface ItemMapper {

    /**
     * 查询所有
     * @return
     */
    @Select("select * from tb_item")
    List<Item> selectAll();

    /**
     * 添加数据
     * @param item
     */
    @Insert("insert into tb_item values(null,#{name},#{price})")
    void add(Item item);
}
