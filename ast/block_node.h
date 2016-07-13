#ifndef __ZU_BLOCK_H__
#define __ZU_BLOCK_H__

#include <cdk/basic_type.h>
#include <cdk/ast/sequence_node.h>

namespace zu {

    class block_node : public cdk::basic_node {
	cdk::sequence_node *_declarations;
	cdk::sequence_node *_statements;

    public:
        inline block_node(int lineno, cdk::sequence_node *declarations, cdk::sequence_node *statements) :
            basic_node(lineno), _declarations (declarations), _statements(statements) {
                
            }
    public:
	inline cdk::sequence_node *decls() {
		return _declarations;
	}
	inline cdk::sequence_node *stmts() {
		return _statements;
	}
	
	/*const char *name() const {
            return "Block";
            
        }*/

        void accept(basic_ast_visitor *sp, int level) {
            sp->do_block_node(this, level);
        }
    };

} // zu

#endif
