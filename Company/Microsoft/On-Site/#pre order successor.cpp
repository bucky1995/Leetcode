function preOrderSuccessor(node){
   if(!node) return

   if(node.left) return node.left
   if(node.right) return node.right

   let parent = node.parent

   while(parent && parent.right === node) {
     node = node.parent
     parent = parent.parent
   }

   if(!parent) return null // we backtracked till root, so no successor

   return parent.right
}



https://stackfull.dev/tree-efficient-traversal-with-parent-pointer