/*!
    \file path.inl
    \brief Filesystem path wrapper inline implementation
    \author Ivan Shynkarenka
    \date 11.08.2016
    \copyright MIT License
*/

namespace CppCommon {

inline Path& Path::Assign(const Path& path)
{
    _path = path._path;
    return *this;
}

inline Path& Path::Concat(const Path& path)
{
    _path.append(path._path);
    return *this;
}

inline char Path::separator() noexcept
{
#if defined(_WIN32) || defined(_WIN64)
    return '\\';
#elif defined(unix) || defined(__unix) || defined(__unix__)
    return '/';
#endif
}

inline void swap(Path& path1, Path& path2)
{
    using std::swap;
    swap(path1._path, path2._path);
}

} // namespace CppCommon