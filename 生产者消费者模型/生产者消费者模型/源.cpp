#define _CRT_SECURE_NO_WARNINGS 1

/*桌子上有一只盘子，每次只能向其中放入一个水果。爸爸专向盘子中放苹果，妈妈专向盘子中放橘子，
儿子专等吃盘子中的橘子，女儿专等吃盘子中的苹果。
只有盘子为空时，爸爸或妈妈就可向盘子中放一个水果；
仅当盘子中有自己需要的水果时，儿子或女儿可以从盘子中取出。*/
semaphore plate = 1, apple = 0, orang = 0;
Dad()//父亲进程
{
	while (1)
	{
		P(plate);//只能有一个人操作（放置、获取）盘子
		put a apple;
		V(apple);//让apple的量+1，通知等待苹果的进程可以来获取苹果了
	}
}
Mom()//母亲进程
{
	while (1)
	{
		P(plate);
		put a orang;
		V(orang);
	}
}
Son()//儿子进程
{
	while (1)
	{
		P(orang);//这里要注意，不用P（plate)因为盘子容量只有1，当儿子拿橘子的时候说明盘中有橘子没苹果，女儿并不会操作盘子
		catch a orang;
		V(plate);//通知等待的生产者，盘子可以放东西了
	}
}
Daugther()//女儿进程
{
	while (1)
	{
		P(apple);
		catch a apple;
		V(apple);//通知等待的进程，可以放东西了
	}
}