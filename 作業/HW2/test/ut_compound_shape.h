#pragma once

#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/dfs_compound_iterator.h"
#include "../src/iterator/bfs_compound_iterator.h"

#include <list>


// class CompoundShapeTest: public ::testing::Test {
//     protected:
//         CompoundShapeTest(){}
//         ~CompoundShapeTest(){}
        
//         void SetUp() override{
//             // Code here will be called immediately after the constructor (right
//             // before each test)
//             c = new Circle(10.0);
//             r = new Rectangle(10.0, 2.0);
//             cs = new CompoundShape();
//         }

//         void TearDown() override{
//             // Code here will be called immediately after each test (right
//             // before the destructor).
//             delete cs;
//         }

//     // Class members declared here can be used by all tests in the test suite
//     Shape* cs;
//     Shape* c;
//     Shape* r;
// };

// TEST_F(CompoundShapeTest, Creation) {
//      ASSERT_TRUE(typeid(*cs)==typeid(CompoundShape));
// }


TEST(CaseCompoundShape, CompoundShape_Creation_Should_Be_Working){
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    cs->addShape(circle);
    cs->addShape(rectangle);

    // Excepted: first element is circle, second element is rectangle (typeid() to check the same is or not)
    Iterator* it = cs->createBFSIterator();
    it->first();
    //ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*circle).name());
    ASSERT_EQ(it->currentItem(), circle);


    it->next();
    //ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*rectangle).name());
    ASSERT_EQ(it->currentItem(), rectangle);
    
    // deallocate occupied memory
    delete it;
    delete cs;
}


TEST(CaseCompoundShape, isDone_Shold_Be_Working){
    Point p1(0, 0);
    Point p2(0, 5);
    TwoDimensionalVector vec1(&p1, &p2);
    CompoundShape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    cs->addShape(circle);
    
    Iterator* it = cs->createBFSIterator();
    it->first();
    //ASSERT_EQ(it->currentItem(), circle);
    
    it->next();
    ASSERT_TRUE(it->isDone());
    
    // deallocate occupied memory
    delete it;
    delete cs;
}


TEST(CaseCompoundShape, DeleteShape_Shold_Be_Working){
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    cs->addShape(circle);
    cs->addShape(rectangle);
    cs->deleteShape(circle);

    Iterator* it = cs->createBFSIterator();
    it->first();
    ASSERT_EQ(it->currentItem(), rectangle);
    
    
    it->next();
    ASSERT_TRUE(it->isDone());
   
   
    // deallocate occupied memory
    delete it;
    delete cs;
}




TEST(CaseCompoundShape, Area_Shold_Be_Working){
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* it = cs->createBFSIterator();
    it->first();
    ASSERT_NEAR(5 * 5 * M_PI, it->currentItem()->area(), 0.01);
    
    
    it->next();
    ASSERT_EQ(5 * 5, it->currentItem()->area());
    ASSERT_TRUE(!it->isDone());
   
    it->next();
    ASSERT_TRUE(it->isDone());
   
    // deallocate occupied memory
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, Perimeter_Shold_Be_Working){
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* it = cs->createBFSIterator();
    it->first();
    ASSERT_NEAR(2 * 5 * M_PI, it->currentItem()->perimeter(), 0.01);
    
    
    it->next();
    ASSERT_EQ(20, it->currentItem()->perimeter());
    ASSERT_TRUE(!it->isDone());
   
    it->next();
    ASSERT_TRUE(it->isDone());
   
    // deallocate occupied memory
    delete it;
    delete cs;
}



TEST(CaseCompoundShape, CS1_add_CS2_Shold_Be_Working){  // 雙層測試
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    Shape* circle2 = new Circle(&vec3);

    cs->addShape(circle);
    cs->addShape(rectangle);

    Shape* cs2 = new CompoundShape();
    cs2->addShape(circle2);
    cs2->addShape(cs);


    Iterator* it = cs2->createBFSIterator();
    it->first();
    ASSERT_NEAR(3 * 3 * M_PI, it->currentItem()->area(), 0.01);
    
    
    it->next();
    ASSERT_NEAR(5 * 5 * M_PI + 25 , it->currentItem()->area(), 0.01);    //他會把cs的所有area()全加起來啦 

    Iterator* it2 = cs->createBFSIterator();
    it2->first();
    ASSERT_NEAR(5 * 5 * M_PI, it2->currentItem()->area(), 0.01); 
   
    it2->next();
    ASSERT_NEAR(5 * 5, it2->currentItem()->area(), 0.01); 

    it2->next();
    ASSERT_TRUE(it2->isDone());
   
    // deallocate occupied memory
    delete it;
    delete cs;
}


TEST(CaseCompoundShape, Info_Shold_Be_Correct){
    Point p1(0, 0);
    Point p2(0, 5);
    Point p3(5, 0);
    Point p4(0, 3);
    
    TwoDimensionalVector vec1(&p1, &p2);
    TwoDimensionalVector vec2(&p1, &p3);
    TwoDimensionalVector vec3(&p1, &p4);
    
    
    //CompoundShape* cs = new CompoundShape();
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(&vec1);
    Shape* rectangle = new Rectangle(&vec1, &vec2);
    cs->addShape(circle);
    cs->addShape(rectangle);

    std::string expected = "CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (0.00, 5.00)), Vector ((0.00, 0.00), (5.00, 0.00))))";
    ASSERT_EQ(cs->info(), expected);
   
    // deallocate occupied memory
    delete cs;
}