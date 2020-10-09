---
# Feel free to add content and custom Front Matter to this file.
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

layout: home
title: Paper
layout: default
---
<!-- Mathjax -->
<script type="text/javascript">
    window.MathJax = {
        tex: {
            packages: ['base', 'ams']
        },
        loader: {
            load: ['ui/menu', '[tex]/ams']
        },
        startup: {
            ready() {
                MathJax.startup.defaultReady();
                const Macro = MathJax._.input.tex.Symbol.Macro;
                const MapHandler = MathJax._.input.tex.MapHandler.MapHandler;
                const Array = MathJax._.input.tex.ams.AmsMethods.default.Array;
                const env = new Macro('psmallmatrix', Array, [null, '(', ')', 'c', '.333em', '.2em', 'S', 1]);
                MapHandler.getMap('AMSmath-environment').add('psmallmatrix', env);
            }
        }
    };
</script>
<script type="text/javascript" id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml.js">
</script>


<!-- Contents -->
# Introduction

In this paper we will be looking at the construction, deletion, and traversal complexities of simple (or intuitive) graph data structures in the C++ standard library (STL). We first discuss all designed graphs and their worst case complexities for the above mentioned operations. We will then describe how these graphs perform in real time, followed by the results, which are interactive, and a discussion. We conclude with a brief summary and recommendation for typical "student" workloads. 

# Graphs
## Adjacency List & Adjacnecy Matrix
$$\mathcal{O}(n)$$ I/Os might be needed to 

## Adjacency Deque
## Adjacency Forward List
## Adjacency Vector
## Adjacency BST
## Adjacency Set
## Adjacency Matrix Vector

# Evaluation

## Construction
## Deletion
## Traversal 

# Results

# Discussion

# Conclusion