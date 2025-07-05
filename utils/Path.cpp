#include "Path.hpp"


Path::Path()
{}

Path::Path(const Path& other)
{
    *this = other;
}

Path& Path::operator=(const Path& other)
{
    this->components = other.components;
    return (*this);
}

Path::~Path()
{}


Path::Path(const std::string& path)
{
    this->set_path(path);
}

Path::Path(const t_strings& components)
{
    this->components = components;
}

Path Path::operator+(const Path& other)
{
    t_strings joined(this->components);

    joined.insert(joined.end(), other.components.begin(), other.components.end());
    return (Path(joined));
}


void Path::set_path(const std::string& path)
{
    std::stringstream ss(ft_strtrim(path, '/'));
    std::string component;

    while (std::getline(ss, component, '/'))
        this->components.push_back(component);
}

std::string Path::get_string() const
{
    std::string path_str;

    for (size_t i = 0; i < this->components.size(); ++i)
    {
        if (i < this->components.size() - 1)
            path_str += this->components[i] + "/";
        else
            path_str += this->components[i];
    }
    return (path_str);
}
