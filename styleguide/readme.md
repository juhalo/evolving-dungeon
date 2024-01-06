# Evolving Dungeon's Style Guide

The project mostly uses [WebKit Code Style Guidelines](https://webkit.org/code-style-guidelines/#classes) as the basis for the style. Below are changes and additions to these guidelines.

## Table of Contents

- [File Names](#file-names)
- [Namespaces](#namespaces)
- [Formatting](#formatting)

## File Names

Header files use the .hpp file extension instead of the .h that WebKit recommends. This is done to keep it more in line with SFML as well as for a personal preference.

## Namespaces

Naming conventions for the namespaces follow WebKit conventions, but other rules for them align more with [Google's](https://google.github.io/styleguide/cppguide.html#Namespaces). Rules copied are:

1. Terminate multi-line namespaces with comments `}  // namespace namespace-name`
2. Wrap whole .cpp/.hpp file after includes/declarations with a namespace
3. Do not declare anything in namespace std, due to this being undefined behavior
4. Do not use using-directive for making all names from a namespace usable (but you may use it to make some available)
5. Do not use Namespace aliases at namespace scope in header files except in explicitly marked internal-only namespaces, because anything imported into a namespace in a header file becomes part of the public API exported by that file
6. Do not use inline namespaces

Other rules:

1. Namespaces must be either abbreviations or their names must be singular instead of a plural
2. Namespaces must start with a capitalized letter and every letter in an abbreviation must be capitalized (from WebKit)

## Formatting

Contrary to WebKit's style, after open bracket, aligning is performed.
