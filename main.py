def define_env(env):
    @env.macro
    def include_example(path):
        return "!!! example \"ソースコード\"\n\t" + get_url(path) + "\n" + inline_cpp(path) + "\n"

def inline_cpp(path):
    source = include_file(path)
    return f"```C++\n{source}\n```"

def get_url(path):
    return f"[{path}](https://github.com/Kotakku/cpp_robotics/blob/develop/{path})"
    
def include_file(filename):
    """
    Include a file's content
    """
    with open(filename, 'r') as file:
        content = file.read()
    return content