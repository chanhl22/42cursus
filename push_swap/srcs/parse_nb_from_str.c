/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nb_from_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:40:42 by chanhlee          #+#    #+#             */
/*   Updated: 2021/05/29 11:41:14 by chanhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lstnum *add_num_to_struct(long long num)
{
	t_lstnum *new_num; //새로운 숫자를 받을 구조체변수

	if (num > INT_MAX || num < INT_MIN) //범위 넘어가면 에러처리
		ft_error();
	new_num = (t_lstnum *)ft_memalloc(sizeof(t_lstnum)); //새로운 숫자를 구조체 공간을 할당해서 넣는다.
	new_num->n = num;									 //숫자를 연결리스트에 넣는다.
	new_num->next = NULL;								 //다음연결리스트는 null
	return (new_num);
}

static void lst_addend(t_lstnum **backtrack, t_lstnum *new_num)
{
	t_lstnum *tmp;

	if (*backtrack == NULL) //예외처리
		return;
	tmp = *backtrack; //새로운 변수에 a스택 end값을 담는다.
	while (tmp->next) //다음 값이 null이 아니라면 다음 노드값을 tmp에 넣는다. 없어도 상관 없을듯?
		tmp = tmp->next;
	/*
	스택의 제일 위의 값은 head, 제일 밑의 값은 end
	*/
	tmp->next = new_num;	//temp가 가리키는 end노드에서 다음 노드를 가리키는 값으로 입력받은 값을 넣은 노드를 넣는다.
	tmp = tmp->next;		//다음 노드를 가리키는 값을 다시 tmp에 넣는다.
	tmp->prev = *backtrack; //이전 노드를 가리키는 값에 end를 담는다.
	*backtrack = tmp;		//end노드에 tmp를 담는다.
}

//리스트에 추가
static void add_nb_to_list(t_stack *s, t_lstnum *new_num, char *str, int *i)
{
	while (str[*i])
	{
		//쭉쭉 예외처리
		while (ft_isblank(str[*i]))
			(*i)++;
		if (str[*i] == '\0')
			break;
		if (!ft_isdigit(str[*i]) && !ft_isblank(str[*i]) && str[*i] != '-' && str[*i] != '+' && str[*i] != '\0')
			ft_error();
		if (ft_isdigit(str[*i]) && !ft_isdigit(str[*i + 1]) && !ft_isblank(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		if ((str[*i] == '-' || str[*i] == '+') && !ft_isdigit(str[*i + 1]) && str[*i + 1] != '\0')
			ft_error();
		//첫번째 연결리스트에 입력받은 값을 넣는다.
		new_num = add_num_to_struct(ft_atoill(&str[*i]));
		//마지막 end값을 추가한다.
		lst_addend(&s->end, new_num);
		if (str[*i] == '-' || str[*i] == '+')
			(*i)++;
		while (ft_isdigit(str[*i]))
			(*i)++;
		if (str[*i] && !ft_isblank(str[*i]))
			ft_error();
	}
}

//첫번 째 입력값을 파싱해서 뭔지 알아낸다.
void parse_nb_from_first_str(t_stack *a, char *str)
{
	int i; // 입력 받은 문자열 포인터를 하나씩 확인하기 위한 변수
	t_lstnum *new_num;

	new_num = NULL;
	i = 0;
	if (!str) // str이 null일 때
		return;
	while (ft_isblank(str[i])) // "\t", " " 검사, 문자가 거짓이면 0반환, 참이면 0이 아닌 값 반환, "\t", " "이면 포인터 이동
		i++;
	// 숫자가 아니면 true, -가 아니라면 true, +가 아니라면 true
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		ft_error();									  //에러
	a->head->n = ft_atoill(&str[i]);				  //long long atoi, 스택에 데이터를 저장, 처음 받은 값이 head
	if (a->head->n > INT_MAX || a->head->n < INT_MIN) //longlong 범위를 넘어가면 에러
		ft_error();
	a->end = a->head;					//처음 받은 값이 스택의 제일 위에 있는데 end값도 동일하게 넣어줌, next노드를 연결하기 위함
	if (str[i] == '-' || str[i] == '+') //-와 +일 경우 포인터 이동
		i++;
	while (ft_isdigit(str[i])) //숫자라면 포인터 이동
		i++;
	if (str[i] && !ft_isblank(str[i])) //null이거나 "\t", " " 이면 에러 출력
		ft_error();
}

// 두번째 부터 값을 받아서 파싱
void parse_nb_from_second_str(t_stack *a, char *str)
{
	int i;
	t_lstnum *new_num; //입력 받은 숫자

	new_num = NULL;
	i = 0;
	if (!str)
		return;
	add_nb_to_list(a, new_num, str, &i);
}
