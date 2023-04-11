package com.cc.web;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/MyServlet")
public class MyServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int statusCode = Integer.parseInt(request.getParameter("statusCode"));

        PrintWriter out = response.getWriter();

        switch (statusCode) {
            case 200:
                response.setStatus(HttpServletResponse.SC_OK);
                out.write("<h1>200 OK</h1>");
                break;
            case 302:
                response.setStatus(HttpServletResponse.SC_FOUND);
                String contextPath = request.getContextPath();
                response.sendRedirect(contextPath + "/resp1");
                out.write("<h1>302 FOUND</h1>");
                break;
            case 304:
                response.setStatus(HttpServletResponse.SC_NOT_MODIFIED);
                out.write("<h1>304 Not Modified</h1>");
                break;
            case 404:
                response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                out.write("<h1>404 Not Found</h1>");
                break;
            case 500:
                response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
                out.write("<h1>500 INTERNAL SERVER ERROR</h1>");
                break;
            default:
                response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                out.write("<h1>Bad Request</h1>");
        }

        out.write("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        this.doGet(request, response);
    }

    @Override
    protected void doPut(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        this.doHead(request, response);
    }

    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        this.doHead(request, response);

    }

    @Override
    protected void doHead(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        int statusCode = Integer.parseInt(request.getHeader("statusCode"));

        switch (statusCode) {
            case 200:
                response.setStatus(HttpServletResponse.SC_OK);
                break;
            case 302:
                response.setStatus(HttpServletResponse.SC_FOUND);
                String contextPath = request.getContextPath();
                response.sendRedirect(contextPath + "/resp1");
                break;
            case 304:
                response.setStatus(HttpServletResponse.SC_NOT_MODIFIED);
                break;
            case 404:
                response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                break;
            case 500:
                response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
                break;
            default:
                response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
        }

    }

    @Override
    protected void doOptions(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doHead(request,response);
        response.setHeader("Allow", "GET, POST, PUT, DELETE, OPTIONS");
    }
}


