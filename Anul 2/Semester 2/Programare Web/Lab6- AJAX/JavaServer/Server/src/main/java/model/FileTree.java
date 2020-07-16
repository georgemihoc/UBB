package model;

import java.util.List;

public class FileTree {
    int id;
    List<FileTree> subChildren;
    boolean isFile;
    String name;
    String path;
    String text;
    List<FileTree> allChildren;

    public FileTree(int id, List<FileTree> subChildren, boolean isFile, String name, String path, String text, List<FileTree> allChildren) {
        this.id = id;
        this.subChildren = subChildren;
        this.isFile = isFile;
        this.name = name;
        this.path = path;
        this.text = text;
        this.allChildren = allChildren;
    }



    public FileTree(String name,String path) {
        this.name = name;
        this.path = path;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<FileTree> getSubChildren() {
        return subChildren;
    }

    public void setSubChildren(List<FileTree> subChildren) {
        this.subChildren = subChildren;
    }

    public boolean isFile() {
        return isFile;
    }

    public void setFile(boolean file) {
        isFile = file;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public List<FileTree> getAllChildren() {
        return allChildren;
    }

    public void setAllChildren(List<FileTree> allChildren) {
        this.allChildren = allChildren;
    }
}
