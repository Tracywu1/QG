package com.cc.service;

import com.cc.po.User;

import java.util.List;

public interface UserService {
    /**

     * 删除
     * @param id
     */
    void delete(Integer id);

    /**

     * 新增用户
     * @param user
     */
    void save(User user);

    /**

     * 根据ID查询用户
     * @param id
     * @return
     */
    User getById(Integer id);

    /**

     * 更新用户
     * @param user
     */
    void modify(User user);

    /**

     * 用户登录
     * @param user
     * @return
     */
    User login(User user);

    /**
     * 用户注册
     *
     * @param user
     * @return
     */
    boolean register(User user);
}
