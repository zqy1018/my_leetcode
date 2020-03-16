class FileSystem:

    def __init__(self):
        self.root = dict()

    def ls(self, path: str):
        if path == '/':
            lis = list(self.root.keys())
            lis.sort()
            return lis
        else:
            cur, l = 1, len(path)
            node = self.root
            while True:
                lst = cur
                while cur < l and path[cur] != '/':
                    cur += 1
                name = path[lst: cur]
                node = node[name]
                if cur == l:
                    # 是文件夹或者文件
                    if type(node) == str:
                        return [name]
                    else:
                        lis = list(node.keys())
                        lis.sort()
                        return lis
                else:
                    cur += 1
            return []           # 占位符

    def mkdir(self, path: str) -> None:
        lis = path.lstrip("/").split("/")
        cur = self.root
        for name in lis:
            if name not in cur:
                cur[name] = dict()
            cur = cur[name]

    def addContentToFile(self, filePath: str, content: str) -> None:
        lis = filePath.lstrip("/").split("/")
        cur = self.root
        for name in lis[: -1]:
            cur = cur[name]
        name = lis[-1]
        if name not in cur:
            cur[name] = content
        else:
            cur[name] += content

    def readContentFromFile(self, filePath: str) -> str:
        lis = filePath.lstrip("/").split("/")
        cur = self.root
        for name in lis:
            cur = cur[name]
        return cur

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)

a = FileSystem()
print(a.ls("/"))
a.mkdir("/a/b/c")
a.addContentToFile("/a/b/c/d","hello")
print(a.ls("/"))
print(a.readContentFromFile("/a/b/c/d"))