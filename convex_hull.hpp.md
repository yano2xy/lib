---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex_hull.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \n// [\u6CE8\u610F] \u52D5\u4F5C\u672A\u78BA\u8A8D\ntemplate <class T, class S>\
    \ std::vector<std::pair<T, S>> convex_hull(std::vector<std::pair<T, S>> ps) {\n\
    \    std::sort(ps.begin(), ps.end());\n    int n = ps.size();\n    if (n <= 2)\
    \ return ps;\n    // \u4E0A\u5074\u51F8\u5305\n    std::vector<std::pair<T, S>>\
    \ stH;\n    for (int i = n - 1; i >= 0; i--) {\n        auto &[px, py] = ps[i];\n\
    \        while (stH.size() >= 2) {\n            auto &[ax, ay] = stH[stH.size()\
    \ - 1];\n            auto &[bx, by] = stH[stH.size() - 2];\n            if ((ax\
    \ - bx) * (py - by) > (ay - by) * (px - bx)) break;\n            stH.pop_back();\n\
    \        }\n        stH.push_back(ps[i]);\n    }\n    // \u4E0B\u5074\u51F8\u5305\
    \n    std::vector<std::pair<T, S>> stL;\n    for (int i = 0; i < ps.size(); i++)\
    \ {\n        auto &[px, py] = ps[i];\n        while (stL.size() >= 2) {\n    \
    \        auto &[ax, ay] = stL[stL.size() - 1];\n            auto &[bx, by] = stL[stL.size()\
    \ - 2];\n            if ((ax - bx) * (py - by) > (ay - by) * (px - bx)) break;\n\
    \            stL.pop_back();\n        }\n        stL.push_back(ps[i]);\n    }\n\
    \n    std::reverse(stH.begin(), stH.end());\n    for (int i = stL.size() - 2;\
    \ i >= 1; i--) stH.push_back(stL[i]);\n    return stH;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n// [\u6CE8\u610F\
    ] \u52D5\u4F5C\u672A\u78BA\u8A8D\ntemplate <class T, class S> std::vector<std::pair<T,\
    \ S>> convex_hull(std::vector<std::pair<T, S>> ps) {\n    std::sort(ps.begin(),\
    \ ps.end());\n    int n = ps.size();\n    if (n <= 2) return ps;\n    // \u4E0A\
    \u5074\u51F8\u5305\n    std::vector<std::pair<T, S>> stH;\n    for (int i = n\
    \ - 1; i >= 0; i--) {\n        auto &[px, py] = ps[i];\n        while (stH.size()\
    \ >= 2) {\n            auto &[ax, ay] = stH[stH.size() - 1];\n            auto\
    \ &[bx, by] = stH[stH.size() - 2];\n            if ((ax - bx) * (py - by) > (ay\
    \ - by) * (px - bx)) break;\n            stH.pop_back();\n        }\n        stH.push_back(ps[i]);\n\
    \    }\n    // \u4E0B\u5074\u51F8\u5305\n    std::vector<std::pair<T, S>> stL;\n\
    \    for (int i = 0; i < ps.size(); i++) {\n        auto &[px, py] = ps[i];\n\
    \        while (stL.size() >= 2) {\n            auto &[ax, ay] = stL[stL.size()\
    \ - 1];\n            auto &[bx, by] = stL[stL.size() - 2];\n            if ((ax\
    \ - bx) * (py - by) > (ay - by) * (px - bx)) break;\n            stL.pop_back();\n\
    \        }\n        stL.push_back(ps[i]);\n    }\n\n    std::reverse(stH.begin(),\
    \ stH.end());\n    for (int i = stL.size() - 2; i >= 1; i--) stH.push_back(stL[i]);\n\
    \    return stH;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex_hull.hpp
  requiredBy: []
  timestamp: '2024-02-18 12:11:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex_hull.hpp
layout: document
redirect_from:
- /library/convex_hull.hpp
- /library/convex_hull.hpp.html
title: convex_hull.hpp
---
